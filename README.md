<div align="center">

# 🧠 Operating System Lab

### *Where processes are born, live, wait, and sometimes become zombies* 🧟



![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)




![Platform](https://img.shields.io/badge/Platform-Linux-black?style=for-the-badge&logo=linux)




![Topic](https://img.shields.io/badge/Topic-Process%20Management-orange?style=for-the-badge)




![Programs](https://img.shields.io/badge/Programs-17-brightgreen?style=for-the-badge)



</div>

---

## 🌳 The Story So Far

```
        🧑 Parent
       /    |    \
    👶     👶     👶      ← fork() gives birth
    |
    👶                    ← grandchild!
```

This repo is my journey through the world of processes: how they are **created** (`fork`), how they **talk** (`pipe`), how they **transform** (`exec`), and how they **wait** for each other (`wait`).

---

## ⚡ Quick Start

```bash
# 1. Clone the repo
git clone https://github.com/<snehasharmaa912-ops>/operatingsystemlab.git
cd operatingsystemlab

# 2. Compile any program
gcc filename.c -o output

# 3. Run it
./output
```

---

## 🗓️ Lab Timeline

| 📅 Date | 🎯 Theme | 🧩 Programs |
|---------|----------|-------------|
| 31 July | Birth of Processes | 11 |
| 7 August | Parent-Child Teamwork | 2 |
| 17 August | Pipes: Secret Tunnels | 2 |
| 18 August | Files + Pipes Combined | 2 |

---

## 🍼 31 July: *The Birth of Processes*

> *"Every process has a parent. Even the ones that get abandoned."*

### 🔹 Classwork

| # | 🎯 Question | 💻 Code |
|---|-------------|---------|
| 1 | 🆔 Print the **PID** and **PPID** of both parent and child processes | [q1_pid_ppid.c](31July/q1_pid_ppid.c) |
| 2 | 🗣️ Print **"Parent Process"** / **"Child Process"** using the return value of `fork()` | [q2_parent_child_msg.c](31July/q2_parent_child_msg.c) |
| 3 | ⏳ Child prints **1 to 5**, parent waits using `wait()` | [q3_child_count_wait.c](31July/q3_child_count_wait.c) |
| 4 | 🔢 Child prints the **Fibonacci** series, parent calculates the **factorial** | [q4_fib_factorial.c](31July/q4_fib_factorial.c) |
| 5 | 👨‍👧‍👦 Child prints Fibonacci and creates a **grandchild** for factorial; parent computes the **sum of first n naturals** | [q5_fib_factorial_sum.c](31July/q5_fib_factorial_sum.c) |

### 🔸 Assignment

| # | 🎯 Question | 💻 Code |
|---|-------------|---------|
| 1 | ⚖️ Parent prints **even** (1–20), child prints **odd** (1–20) | [q1_even_odd.c](31July/Assignment/q1_even_odd.c) |
| 2 | 👶👶👶 Create **three children**, each printing its PID, PPID and child number | [q2_three_children.c](31July/Assignment/q2_three_children.c) |
| 3 | 🚪 Child **exits with status 10**, parent reads it using `wait()` | [q3_exit_status.c](31July/Assignment/q3_exit_status.c) |
| 4 | 🥺 Demonstrate an **orphan process** | [q4_orphan_process.c](31July/Assignment/q4_orphan_process.c) |
| 5 | 🧟 Demonstrate a **zombie process** (observe with `ps`) | [q5_zombie_process.c](31July/Assignment/q5_zombie_process.c) |
| 6 | 🔄 Use `fork()`, `exec()` and `wait()` to run the **`date`** command | [q6_exec_date.c](31July/Assignment/q6_exec_date.c) |

---

## 🤝 7 August: *Parent-Child Teamwork*

> *"Divide the work, conquer the problem."*

| # | 🎯 Question | 💻 Code |
|---|-------------|---------|
| 1 | 🌀 Child prints the **Fibonacci** series up to n terms, parent prints all **Armstrong numbers** up to n | [fib_armstrong.c](7aug/fib_armstrong.c) |
| 2 | 🔍 Child checks if a number is **prime**, parent calculates its **factorial** | [prime_factorial.c](7aug/prime_factorial.c) |

---

## 🚇 17 August: *Pipes, the Secret Tunnels*

> *"When processes need to whisper to each other."*

| # | 🎯 Question | 💻 Code |
|---|-------------|---------|
| 1 | 🔤 Child takes a **string** as input and sends it through a pipe; parent prints all its **permutations** | [string_permute.c](17Aug/string_permute.c) |
| 2 | ➕ Parent takes **n array elements**; child calculates the **sum** and sends it via pipe; parent checks if the sum is **prime** | [sum_prime.c](17Aug/sum_prime.c) |

---

## 📁 18 August: *Files Meet Processes*

> *"One writes, the other reads."*

| # | 🎯 Question | 💻 Code |
|---|-------------|---------|
| 1 | 📝 Parent creates **`input.txt`** and writes name, university roll no. and class; child **reads and prints** the file | [Input.c](18aug/Input.c) |
| 2 | 🧮 Parent calculates the **sum of an array**; child checks whether the sum is **prime** (via pipe) | [SumisPrime.c](18aug/SumisPrime.c) |

---

## 🧰 System Calls Cheat Sheet

| Call | 💡 What it does |
|------|----------------|
| `fork()` | Clones the current process (parent → child) |
| `getpid()` / `getppid()` | Returns own PID / parent's PID |
| `wait()` | Parent pauses until the child finishes |
| `exit()` | Terminates the process with a status code |
| `execlp()` | Replaces the process image with a new program |
| `pipe()` | Creates a one-way communication channel |
| `read()` / `write()` | Receive / send data through a pipe |
| `sleep()` | Pauses execution for some seconds |

---

## 🧟 Process Zoo

| Species | How it happens | Demo |
|---------|----------------|------|
| 🧟 **Zombie** | Child finishes but parent hasn't called `wait()` | [q5_zombie_process.c](31July/Assignment/q5_zombie_process.c) |
| 🥺 **Orphan** | Parent dies before the child; `init` adopts it | [q4_orphan_process.c](31July/Assignment/q4_orphan_process.c) |
| 👨‍👧 **Normal** | Parent waits for the child to finish | [q3_child_count_wait.c](31July/q3_child_count_wait.c) |

---

## 📂 Repository Map

```
operatingsystemlab/
├── 📁 31July/
│   ├── q1_pid_ppid.c
│   ├── q2_parent_child_msg.c
│   ├── q3_child_count_wait.c
│   ├── q4_fib_factorial.c
│   ├── q5_fib_factorial_sum.c
│   └── 📁 Assignment/
│       ├── q1_even_odd.c
│       ├── q2_three_children.c
│       ├── q3_exit_status.c
│       ├── q4_orphan_process.c
│       ├── q5_zombie_process.c
│       └── q6_exec_date.c
├── 📁 7aug/
│   ├── fib_armstrong.c
│   └── prime_factorial.c
├── 📁 17Aug/
│   ├── string_permute.c
│   └── sum_prime.c
└── 📁 18aug/
    ├── Input.c
    └── SumisPrime.c
```

---

<div align="center">

### 👨‍💻 Made by
**Sneha Sharma** · Roll No: `60` · Year: 'B.Tech CSE 5th Sem' · Section: `iOS` 

</div>
