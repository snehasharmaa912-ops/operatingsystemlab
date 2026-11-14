<div align="center">

# 🧠 Operating System Lab

### *Where processes are born, live, wait, and sometimes become zombies* 🧟

![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Platform](https://img.shields.io/badge/Platform-Linux-black?style=for-the-badge&logo=linux)
![Topic](https://img.shields.io/badge/Topic-Process%20Management%20%26%20IPC-orange?style=for-the-badge)
![Programs](https://img.shields.io/badge/Programs-36-brightgreen?style=for-the-badge)

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

This repo is my journey through the world of operating systems: how processes are **created** (`fork`), how they **talk** (`pipe`, FIFO, message queues, shared memory), how they **transform** (`exec`), how they **wait** for each other (`wait`), and how the OS **schedules** them and manages **memory pages**.

---

## ⚡ Quick Start

```bash
# 1. Clone the repo
git clone https://github.com/snehasharmaa912-ops/operatingsystemlab.git
cd operatingsystemlab

# 2. Compile any program
gcc filename.c -o output

# 3. Run it
./output
```

> 💡 Programs that come in pairs (FIFO, message queue, shared memory) need **two terminals**: run the writer/sender in one and the reader/receiver in the other, from the **same folder**.

---

## 🗓️ Lab Timeline

| 📅 Date | 🎯 Theme | 🧩 Programs |
|---------|----------|-------------|
| 31 July | Birth of Processes | 11 |
| 7 August | Parent-Child Teamwork | 2 |
| 17 August | Pipes: Secret Tunnels | 2 |
| 18 September | Files + Pipes Combined | 2 |
| 25 September | Zombies, Orphans & File I/O | 4 |
| 16 October | FIFO (Named Pipes) | 2 |
| 23 October | IPC: Pipe, FIFO, Message Queue, Shared Memory | 8 |
| 30 October | CPU Scheduling & Page Replacement | 5 |

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

## 📁 18 September: *Files Meet Processes*

> *"One writes, the other reads."*

| # | 🎯 Question | 💻 Code |
|---|-------------|---------|
| 1 | 📝 Parent creates **`input.txt`** and writes name, university roll no. and class; child **reads and prints** the file | [Input.c](18Sep/Input.c) |
| 2 | 🧮 Parent calculates the **sum of an array**; child checks whether the sum is **prime** (via pipe) | [SumisPrime.c](18Sep/SumisPrime.c) |

---

## 🧟 25 September: *Zombies, Orphans & Files*

> *"Not every process gets a happy ending."*

| # | 🎯 Question | 💻 Code |
|---|-------------|---------|
| 1 | 📂 **Open a file** in the child process | [OpenFileinChildProcess.c](25Sep/OpenFileinChildProcess.c) |
| 2 | 📖 Pass a **filename** from the parent via pipe, child prints even numbers, and the parent **reads the file** | [ReadFileinParent.c](25Sep/ReadFileinParent.c) |
| 3 | 🧟 Demonstrate a **zombie process** | [ZombieProcess.c](25Sep/ZombieProcess.c) |
| 4 | 🥺 Demonstrate an **orphan process** | [OrphanProcess.c](25Sep/OrphanProcess.c) |

---

## 🚰 16 October: *FIFO, the Named Pipe*

> *"A pipe with a name, a file that only passes messages."*

| # | 🎯 Question | 💻 Code |
|---|-------------|---------|
| 1 | ✍️ **Writer** creates a FIFO (`mkfifo`) and sends a message | [Writer.c](Oct16/Writer.c) |
| 2 | 📥 **Reader** reads the message from the FIFO and removes it | [Reader.c](Oct16/Reader.c) |

> ▶️ Run `Writer` in one terminal and `Reader` in another.

---

## 📬 23 October: *Inter-Process Communication*

> *"Four different ways for processes to pass notes."*

| # | 🎯 Topic | 💻 Code |
|---|----------|---------|
| 1 | 🚇 **Unnamed pipe** between parent and child | [pipe.c](Oct23/pipe.c) |
| 2 | 🚰 **FIFO**: writer and reader | [fifowriter.c](Oct23/fifowriter.c) · [fiforeader.c](Oct23/fiforeader.c) |
| 3 | 📨 **Message queue**: sender and receiver | [messagesender.c](Oct23/messagesender.c) · [messagereceiver.c](Oct23/messagereceiver.c) |
| 4 | 🧠 **Shared memory**: writer and reader | [sharedwriter.c](Oct23/sharedwriter.c) · [sharedreader.c](Oct23/sharedreader.c) |
| 5 | ➗ Child sums **even** numbers, parent sums **odd** numbers | [oddevensumfork.c](Oct23/oddevensumfork.c) |

> ⚠️ Run each pair from the **same directory**, because the message queue and shared memory keys come from `ftok(".", ...)`.

---

## ⚙️ 30 October: *Scheduling & Page Replacement*

> *"Who runs next? Who gets evicted?"*

### 🔹 CPU Scheduling

| # | 🎯 Algorithm | 💻 Code |
|---|--------------|---------|
| 1 | 🚶 **FCFS**: First Come First Served | [fcfs.c](Oct30/fcfs.c) |
| 2 | ⚡ **SJF**: Shortest Job First | [sjf.c](Oct30/sjf.c) |
| 3 | 🏅 **Priority** scheduling | [priority.c](Oct30/priority.c) |

### 🔸 Page Replacement

| # | 🎯 Algorithm | 💻 Code |
|---|--------------|---------|
| 1 | 🔁 **FIFO** page replacement | [fifopage.c](Oct30/fifopage.c) |
| 2 | 🕰️ **LRU**: Least Recently Used | [lrupage.c](Oct30/lrupage.c) |

---

## 🧟 Process Zoo

| Species | How it happens | Demo |
|---------|----------------|------|
| 🧟 **Zombie** | Child finishes but parent hasn't called `wait()` | [ZombieProcess.c](25Sep/ZombieProcess.c) |
| 🥺 **Orphan** | Parent dies before the child; `init` adopts it | [OrphanProcess.c](25Sep/OrphanProcess.c) |
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
├── 📁 18Sep/
│   ├── Input.c
│   └── SumisPrime.c
├── 📁 25Sep/
│   ├── OpenFileinChildProcess.c
│   ├── ReadFileinParent.c
│   ├── ZombieProcess.c
│   └── OrphanProcess.c
├── 📁 Oct16/
│   ├── Writer.c
│   └── Reader.c
├── 📁 Oct23/
│   ├── pipe.c
│   ├── fifowriter.c
│   ├── fiforeader.c
│   ├── messagesender.c
│   ├── messagereceiver.c
│   ├── sharedwriter.c
│   ├── sharedreader.c
│   └── oddevensumfork.c
└── 📁 Oct30/
    ├── fcfs.c
    ├── sjf.c
    ├── priority.c
    ├── fifopage.c
    └── lrupage.c
```

---

<div align="center">

### 👨‍💻 Made by
**Sneha Sharma** · Roll No: `98` · B.Tech CSE, 5th Sem · Section: `iOS`

</div>
