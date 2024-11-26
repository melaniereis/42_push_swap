# 🌀 Push Swap

<div align="center">

![Funny Sorting GIF](https://media.giphy.com/media/your-funny-gif-url.gif)

Welcome to **Push Swap**! This project is my implementation of the Push Swap algorithm, part of the **42 coding school** curriculum. It focuses on sorting a stack of integers using a limited set of operations, utilizing the **Turkish algorithm** for optimal performance.

![Push Swap](https://img.shields.io/badge/Project-PushSwap-blue?style=for-the-badge&logo=42)
![Language](https://img.shields.io/badge/Language-C-orange?style=for-the-badge&logo=c)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

</div>

---

## 📚 Table of Contents

<details>
<summary>Click to expand</summary>

- [Overview](#overview)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Operations](#operations)
- [Algorithm](#algorithm)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

</details>

---

## 🔍 Overview

The **Push Swap** project involves sorting data on two stacks (`a` and `b`) with minimal operations. The main goal is to efficiently sort stack `a`.

---

## ✨ Features

- 🚀 **Turkish Algorithm:** Efficient sorting method.
- 🔄 **Flexible Input:** Accepts both strings and multiple arguments.
- 💻 **C Implementation:** Optimized for performance.

---

## 🚀 Getting Started

### 📦 Prerequisites

Make sure you have:

- `cc` compiler or another C compiler
- Make

### 🔧 Installation

Clone the repository and compile the program:

```bash
git clone https://github.com/yourusername/push_swap.git
cd push_swap
make CC=cc
```
## 🖥️ Usage

Run the program with integers as arguments or as a string:

```bash
./push_swap 3 2 5 1 4
```
or

```bash
./push_swap "3 2 5 1 4"
```
This will output the series of operations needed to sort the stack.

## ⚙️ Operations

<details>
<summary>Click to see all operations</summary>

| Operation | Description |
|-----------|-------------|
| `sa` | Swap top two elements of stack A |
| `sb` | Swap top two elements of stack B |
| `ss` | Simultaneous swap of `sa` and `sb` |
| `pa` | Push top element from B to A |
| `pb` | Push top element from A to B |
| `ra` | Rotate stack A up |
| `rb` | Rotate stack B up |
| `rr` | Simultaneous rotation of both stacks |
| `rra` | Reverse rotate stack A |
| `rrb` | Reverse rotate stack B |
| `rrr` | Simultaneous reverse rotation of both stacks |

</details>

## 🧠 Algorithm

This project implements the Turkish algorithm, which efficiently sorts stacks by:

1. Dividing the input into manageable chunks.
2. Sorting each chunk intelligently.
3. Minimizing the number of operations required.

## 🧪 Testing

To test the program, you can use various input formats:

```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```
Make sure to check edge cases like:

- ✅ Already sorted lists
- ❌ Reverse sorted lists
- 🔁 Lists with duplicates
- ⚠️ Very large or negative numbers

## 🤝 Contributing

Contributions are welcome! Please fork this repository and submit a pull request with your improvements or bug fixes.

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

<div align="center">

**Happy Coding! 🎉**

[⬆ Back to top](#-push-swap)

</div>
