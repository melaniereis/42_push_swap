#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "push_swap.h"

typedef struct s_stack_node {
    int value;
    int index;
    int pos;           // Position in the stack
    int target_pos;    // Target position for sorting
    int cost_a;       // Cost to move to stack A
    int cost_b;       // Cost to move to stack B
    struct s_stack_node *next_node;
    struct s_stack_node *prev_node;
} t_stack_node;

void sort_stacks(t_stack_node **a, t_stack_node **b);
void parse_parameters(int argc, char **argv);
void create_stack_a(t_stack_node **a);
void add_rank(t_stack_node *stack);
void set_indices(t_stack_node *stack);
void split_and_push(t_stack_node **a, t_stack_node **b);
void sort_three(t_stack_node **stack);
void move_b_to_a(t_stack_node **a, t_stack_node **b);
void optimize_moves(t_stack_node **a, t_stack_node **b);
void rotate_a_if_needed(t_stack_node **a);
int stack_len(t_stack_node *stack);
int is_sorted(t_stack_node *stack);
t_stack_node *find_cheapest(t_stack_node *stack);
t_stack_node *find_min(t_stack_node *stack);
void pb(t_stack_node **b, t_stack_node **a);
void pa(t_stack_node **a, t_stack_node **b);
void ra(t_stack_node **a);
void rra(t_stack_node **a);
void sa(t_stack_node **a);
void finish_rotation(t_stack_node **stack, int *cost, char stack_name);
void prep_for_push(t_stack_node **stack, int target_pos, char stack_name);

void sort_stacks(t_stack_node **a, t_stack_node **b) {
    int len_a;

    set_indices(*a);
    len_a = stack_len(*a);

    while (len_a > 3) {
        t_stack_node *cheapest = find_cheapest(*a);

        while (*a != cheapest) {
            ra(a); 
        }

        pb(b, a); 
        len_a = stack_len(*a); 
    }

    if (len_a == 3) {
        sort_three(a); 
    }

    while (*b) { 
        optimize_moves(a, b); 
        move_b_to_a(a, b); 
    }

    rotate_a_if_needed(a);
}


void add_rank(t_stack_node *stack) {
    int rank = 1;
    while (stack) {
        stack->rank = rank++;
        stack = stack->next_node;
    }
}

void set_indices(t_stack_node *stack) {
    t_stack_node *tmp;
    int *arr;
    int size;

    size = stack_len(stack);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
	    return;

	tmp = stack;	
	for (int i = 0; i < size; i++) {
	    arr[i] = tmp->value;	
	    tmp = tmp->next_node;	
	}	

	quick_sort(arr, 0, size - 1);

	tmp = stack;	
	while (tmp) {
	    tmp->index = find_index(arr, size, tmp->value);	
	    tmp = tmp->next_node;	
	}	

	free(arr);	
}

void split_and_push(t_stack_node **a, t_stack_node **b) {
    int len_a = stack_len(*a);

    while (len_a > 3) {
        t_stack_node *cheapest = find_cheapest(*a); 

        pb(b, a); 
        len_a = stack_len(*a); 
    }
}

void sort_three(t_stack_node **stack) {
    int top = (*stack)->value;
    int middle = (*stack)->next_node->value;
    int bottom = (*stack)->next_node->next_node->value;

    if (top > middle && middle < bottom && top < bottom)
        sa(stack); 
    else if (top > middle && middle > bottom)
        sa(stack), rra(stack); 
    else if (top > middle && middle < bottom && top > bottom)
        ra(stack); 
    else if (top < middle && middle > bottom && top < bottom)
        sa(stack), ra(stack); 
    else if (top < middle && middle > bottom && top > bottom)
        rra(stack); 
}

void move_b_to_a(t_stack_node **a, t_stack_node **b) {
   prep_for_push(a, (*b)->target_pos, 'a'); 
   pa(a, b); 
}

void optimize_moves(t_stack_node **a, t_stack_node **b) {
   t_stack_node *target_b = *b;
   int min_moves = INT_MAX;
   int best_cost_a = 0;
   int best_cost_b = 0;

   while (target_b) {
       int cost_a = target_b->cost_a;
       int cost_b = target_b->cost_b;

       int total_moves = abs(cost_a) + abs(cost_b);

       if (total_moves < min_moves) {
           min_moves = total_moves;
           best_cost_a = cost_a;
           best_cost_b = cost_b;
       }

       target_b = target_b->next_node;
   }

   while (best_cost_a > 0 && best_cost_b > 0) {
       rr(a, b); // Rotate both stacks
       best_cost_a--;
       best_cost_b--;
   }

   while (best_cost_a < 0 && best_cost_b < 0) {
       rrr(a, b); // Reverse rotate both stacks
       best_cost_a++;
       best_cost_b++;
   }

   finish_rotation(a, &best_cost_a, 'a');
   finish_rotation(b, &best_cost_b, 'b');
}

void rotate_a_if_needed(t_stack_node **a) {
   if (!is_sorted(*a)) { 
       while ((*a)->value != find_min(*a)->value) { 
           ra(a); 
       }
   }
}

int is_sorted(t_stack_node *stack) {
   while (stack && stack->next_node) {
       if (stack->value > stack->next_node->value)
           return 0;
       stack = stack->next_node;
   }
   return 1;
}

t_stack_node *find_cheapest(t_stack_node *stack) {
	t_stack_node *cheapest = stack; 
	int min_cost= INT_MAX; 

	while(stack){ 
	    int total_cost= abs(stack -> cost_a)+ abs(stack -> cost_b); 

	    if(total_cost< min_cost){ 
	        min_cost= total_cost; 
	        cheapest= stack; 
	      } 

	    stack= stack -> next_node; 
	  } 

	return cheapest; 
}

t_stack_node *find_min(t_stack_node *stack) {
	t_stack_node *min = stack;

	while (stack) {
		if (stack->value < min->value)
			min = stack;
		stack = stack->next_node;
	}
	return min;
}


void finish_rotation(t_stackNode** stack,int* cost,char stack_name){
	while(*cost!=0){
	    if(*cost>0){
	        if(stack_name=='A')
	            ra(stack,false);
	        else
	            rb(stack,false);
	        (*cost)--;	
	    }else{
	        if(stack_name=='A')
	            rra(stack,false);
	        else
	            rrb(stack,false);
	        (*cost)++;	
	    }	
	}
}

void prep_for_push(t_stackNode** stack,int target_pos,char stack_name){
	t_StackNode* current=*stack ;
	while(current!=NULL){
	    if(current -> pos==target_pos){
	        break ;
	      }
	    current=current -> next ;
	  }
}
