# 🌀 Push Swap

<div align="center">
  
![Sorting Animation](https://c.tenor.com/jhDKfwDdMfwAAAAd/tenor.gif)

**Push Swap** - My custom solution for the 42 coding school challenge, focusing on stack sorting efficiency with a unique algorithm.

![Project Status](https://img.shields.io/badge/Project-PushSwap-blue?style=for-the-badge&logo=42)
![Programming Language](https://img.shields.io/badge/Language-C-orange?style=for-the-badge&logo=c)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

</div>

---

## 📚 Table of Contents

<details>
<summary>View Contents</summary>

- [Overview](#overview)
- [Key Features](#key-features)
- [Installation](#installation)
- [Usage](#usage)
- [Stack Operations](#stack-operations)
- [Algorithm](#algorithm)
- [Optimizations](#optimizations)
- [Performance Metrics](#performance-metrics)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

</details>

---

## 🔍 Overview

**Push Swap** is an engaging project where the task is to sort integers between two stacks (`a` and `b`) using a limited set of operations. This implementation employs a custom algorithm inspired by but not limited to traditional methods, aiming for the least number of operations possible.

The project revolves around efficiently sorting a stack of integers using two stacks and a predefined set of operations. The goal is to minimize the number of operations while ensuring the stack is sorted in ascending order.

![Push Swap Sorting Video]([https://github.com/melaniereis/42_push_swap/blob/main/push_swap_visualizer.gif])

---

## ✨ Key Features

- **Innovative Algorithm**: A unique sorting method, segmenting and pre-sorting data for efficiency.
- **Input Flexibility**: Handles numbers passed as arguments or in string format.
- **C Language**: Optimized for performance, leveraging C's capabilities.
- **Efficient Operations**: Utilizes a minimal set of stack operations to achieve sorting.

---

## 🚀 Installation

### 📦 Prerequisites

- **C Compiler** (e.g., GCC)
- **Make** tool

### 🔧 Setup

```bash
git clone https://github.com/melaniereis/42_push_swap.git
cd push_swap
make
```
markdown
## 🖥️ Usage

To sort numbers:

```bash
./push_swap 3 2 5 1 4
```
or

```bash
./push_swap "3 2 5 1 4"
```
This will print the sequence of operations to sort the list.
## ⚙️ Stack Operations

<details>
<summary>See Available Operations</summary>

| Operation | Functionality |
|-----------|---------------|
| `sa` | Swap the first 2 elements of stack `a`. |
| `sb` | Swap the first 2 elements of stack `b`. |
| `ss` | Perform `sa` and `sb` together. |
| `pa` | Push the top element from `b` to `a`. |
| `pb` | Push the top element from `a` to `b`. |
| `ra` | Rotate `a` up (first becomes last). |
| `rb` | Rotate `b` up (first becomes last). |
| `rr` | Rotate both `a` and `b` up. |
| `rra` | Reverse rotate `a` (last becomes first). |
| `rrb` | Reverse rotate `b` (last becomes first). |
| `rrr` | Reverse rotate both `a` and `b`. |

</details>

## 🧠 Algorithm

The algorithm follows a step-by-step strategy to sort the stack efficiently:

- **Stack Initialization**: Use a doubly linked list for stack `a`.
- **Segmentation**: Divide `a` into three parts based on their final sorted position.
- **Preliminary Sort**:
  - Move the two smallest segments to `b`, sorting in a way that:
    - The smallest goes to the bottom of `b`.
    - The middle stays at the top of `b`.
  - Elements from the largest segment in `a` are rotated with `ra`.
- **Final Sorting**:
  - Sort the remaining three elements in `a` with a tailored approach, using at most two operations.
  - Continuously find and move elements from `b` back to `a` with minimal operations by evaluating all possible combinations of rotations.

## 🔧 Optimizations

- **Operation Merge**: Combine operations like `ra`+`rb` or `rra`+`rrb` into single moves (`rr`, `rrr`).
- **Redundancy Elimination**: Cancel out operations like `ra` followed by `rra`.

## 📊 Performance Metrics

The program was tested extensively to evaluate its efficiency in terms of the number of moves required to sort stacks of varying sizes. Below are the results:

**For Stacks of Size ≤ 100**
- Total Tests: 201
- Max Moves: 615
- Min Moves: 494
- Average Moves: 546

**For Stacks of Size ≤ 500**
- Total Tests: 201
- Max Moves: 4246
- Min Moves: 3672
- Average Moves: 3980

These results demonstrate the program's ability to handle both small and large stacks efficiently, consistently achieving low move counts.

## 🧪 Testing

Test your implementation with:

```bash
./push_swap 4 67 3 87 23
```
```bash
./push_swap "4 67 3 87 23"
````
Consider testing with:

- ✅ Pre-sorted lists
- ❌ Inversely sorted lists
- 🔁 Lists with duplicates
- ⚠️ Large or extremely small numbers

## 🤝 Contributing

Feel free to fork, contribute improvements, or fix bugs. Pull requests are welcome!

## 📜 License

This project is open-sourced under the MIT License. See [LICENSE](LICENSE) for more information.

<div align="center">

**Let's Master Sorting Together! 🎉**

[⬆ Back to Top](#-push-swap)

</div>
