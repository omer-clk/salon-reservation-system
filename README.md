# Salon Reservation System

A console-based appointment system for hair salons, written in C.

This was my first programming project. I built it to practice C fundamentals: arrays, strings, functions, and file I/O.

## Features

- **Book an appointment:** customers enter their name and phone number and get a queue number (max 20 appointments).
- **Look up / cancel:** customers find their appointment by phone number and can cancel it; the queue shifts automatically.
- **Hairdresser panel:** a password-protected view that lists every appointment.
- **Persistent storage:** appointments are saved to `kayitlarim.txt` and loaded on startup, so data survives restarts.

## Getting Started

### Requirements

- A C compiler (GCC, Clang, or MinGW on Windows)

### Build and run

```bash
make
./kuafor
```

Or without `make`:

```bash
gcc main.c -o kuafor
./kuafor
```

On Windows, run `kuafor.exe` instead.

## Usage

```
-----Ana Menu-----
Mevcut Sira: 0 / 20
Lutfen islem seciniz:
1-Sira Al
2-Sira Sorgula/iptal et
3-Kuafor Girisi
4-Cikis
```

| Option | Description |
| --- | --- |
| 1 - Sira Al | Book a new appointment |
| 2 - Sira Sorgula/iptal et | Look up or cancel an appointment by phone number |
| 3 - Kuafor Girisi | Hairdresser login (lists all appointments) |
| 4 - Cikis | Exit |

## What I Learned

- Working with 2D `char` arrays to store strings
- Reading and writing files with `fopen`, `fprintf`, `fgets`, and `fscanf`
- Handling the input buffer when mixing `scanf` and `fgets`
- Removing an element from an array by shifting the remaining items

## Possible Improvements

- Bounded input (`fgets` / `%11s`) to prevent buffer overflows
- Using a `struct` for customer records instead of parallel arrays
- Dynamic memory instead of a fixed 20-slot limit
