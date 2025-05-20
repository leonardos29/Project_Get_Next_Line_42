# 📄 get_next_line

> A project from the 42 School that implements a function capable of reading a file line by line, handling file descriptors, static memory, and dynamic allocation efficiently.

---

## 🧠 About the Project

The `get_next_line` function allows reading from a file descriptor one line at a time. A "line" is defined as a sequence of characters ending in a newline (`\n`) or EOF (end of file).

This is a fundamental project in the 42 curriculum designed to reinforce understanding of:
- File I/O operations
- Memory allocation
- Buffering strategies
- Static variables in C
- Safe string manipulation

---

## 🔧 Function Prototype

```c
char *get_next_line(int fd);
