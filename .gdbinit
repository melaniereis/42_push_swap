# GDB Settings
set print pretty on
# set print elements 2
set print array on


# main.c
define main
	disp argc
	disp argv
	disp *a->value
	disp *argv@argc
	disp *a
	disp *b
	disp split_flag
end

# errors.c
define error_digit
	disp str_nb
	disp *str_nb
	disp str_nb[1]
end

define error_rep
	disp a
	disp a->value
	disp *a
	disp nb
end

define free_matrix
	disp argv
	disp *argv
	disp **argv
end

define free_all
	disp a
	disp *a
	disp argv
	disp argv[0]
	disp argv[0][0]
	disp *argv
end

# append_mode.c
define append_mode
	disp stack
	disp *stack
	disp nbr
	disp node
	disp *node
	disp last_node
	disp *last_node
end

# stack_init.c
define stack_init
	disp a
	disp *a
	disp **a
	disp **argv
	disp argv[i]
end

# GO GDB GOOO!!!

### Start at main
# fs cmd
# break main
# run 55 77
# main
# refresh

### Start at error_digit
fs cmd
break error_digit_and_sign
run 54 76
refresh
