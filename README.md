# simple_shell
A simple UNIX command interpreter

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This project is a barebones clone of the sh unix command line interpreter, following the guidlines presented by staff - This being restrictions on functions we could use limited to:
######
access (man 2 access)  
chdir (man 2 chdir)  
close (man 2 close)  
closedir (man 3 closedir)  
execve (man 2 execve)  
exit (man 3 exit)  
_exit (man 2 _exit)  
fflush (man 3 fflush)  
fork (man 2 fork)  
free (man 3 free)  
getcwd (man 3 getcwd)  
getline (man 3 getline)  
getpid (man 2 getpid)  
isatty (man 3 isatty)  
kill (man 2 kill)  
malloc (man 3 malloc)  
open (man 2 open)  
opendir (man 3 opendir)  
perror (man 3 perror)  
read (man 2 read)  
readdir (man 3 readdir)  
signal (man 2 signal)  
stat (__xstat) (man 2 stat)  
lstat (__lxstat) (man 2 lstat)  
fstat (__fxstat) (man 2 fstat)  
strtok (man 3 strtok)  
wait (man 2 wait)  
waitpid (man 2 waitpid)  
wait3 (man 2 wait3)  
wait4 (man 2 wait4)  
write (man 2 write)  
######

### Built With

* C programming language
* bash for testing
* sh for reference


<!-- USAGE EXAMPLES -->
## Usage
The shell is executed by compiling the c files, and starting the executable file.
```$
gcc -Wall -Wextra -Werror -pedantic *.c -o ./hsh
```
| C files        | Main Content Description | Function count  |
| ------------- |:-------------:| -----:|
| built_in.c | contains exit and env functions | 2 |
| helpers.c | contains helper functions and main tokenizer function | 5 |
| helpers2.c | contains helper functions for strtok_r | 5 |
| helpers3.c | assortment of functions like realloc and strtok_r | 5 |
| main_shell.c | contains main functions and disassembled functions for main | 3 |
| utilis.c | engine of the project containing vital executer functions | 5 |
| shell_header.h | header file | N\A |

## How to use
### Interactive mode

![](https://github.com/Doro-000/simple_shell/blob/master/image_2021-04-29_11-41-41.png?raw=true)

### Non - Interactive mode
```$
echo "arg.." | ./hsh
```

######

<!-- CONTACT -->
## Contact

Hizkyas Aberra - hizkyastekle@gmail.com

Philimon Derib - philimonderib2019@gmail.com
