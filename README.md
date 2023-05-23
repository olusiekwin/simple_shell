
# Simple Shell

Simple Shell is a basic Unix shell implementation written in C. It provides a simple command-line interface where users can enter commands and execute them. The shell supports both interactive mode, where commands are entered directly by the user, and batch mode, where commands are read from a file and executed.

## Features

- Command execution: Executes commands using the `execve` system call.
- Built-in commands: Supports a few built-in commands like `exit` to exit the shell.
- Batch mode: Reads commands from a file and executes them without prompting for input.
- Prompt: Provides a command prompt in interactive mode for users to enter commands.
- Input handling: Handles user input by reading commands and arguments.
- Error handling: Displays appropriate error messages for failed system calls.

## Getting Started

To compile the Simple Shell program, run the following command:

```
gcc -g -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

To run the shell in interactive mode, simply execute the compiled binary:

```
./hsh
```

To run the shell in batch mode, provide a filename as a command-line argument:

```
./hsh [filename]Certainly! Here's a raw version of the README file content that you can paste directly into your `README.md` file:

```
# Simple Shell

Simple Shell is a basic Unix shell implementation written in C. It provides a simple command-line interface where users can enter commands and execute them. The shell supports both interactive mode, where commands are entered directly by the user, and batch mode, where commands are read from a file and executed.

## Features

- Command execution: Executes commands using the `execve` system call.
- Built-in commands: Supports a few built-in commands like `exit` to exit the shell.
- Batch mode: Reads commands from a file and executes them without prompting for input.
- Prompt: Provides a command prompt in interactive mode for users to enter commands.
- Input handling: Handles user input by reading commands and arguments.
- Error handling: Displays appropriate error messages for failed system calls.

## Getting Started

To compile the Simple Shell program, run the following command:

```
gcc -g -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

To run the shell in interactive mode, simply execute the compiled binary:

```
./hsh
```

To run the shell in batch mode, provide a filename as a command-line argument:

```
./hsh [filename]
```

The file should contain one command per line, and the shell will execute them without prompting for input.

## Usage

Once the shell is running, you can enter commands to execute. The shell will attempt to execute the commands using the `execve` system call. If a command is not recognized as a built-in command, it will be treated as an external command and executed accordingly.

In interactive mode, the shell will display a prompt for entering commands. For example:

```
$ ls -l
$ pwd
$ echo "Hello, world!"
```

To exit the shell, you can use the built-in `exit` command or press Ctrl+C.

In batch mode, the shell will read commands from the specified file and execute them without displaying a prompt.

## Contributing

Contributions to the Simple Shell project are welcome! If you have any ideas, suggestions, or bug reports, please open an issue or submit a pull request on GitHub.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgements

This shell implementation was developed as part of a programming exercise. Special thanks to the developers and contributors of the various resources and tutorials that helped in understanding the concepts and techniques involved in building a shell.

## Contact

For any inquiries or questions, feel free to contact us at [email address].
```

Feel free to modify and customize the README file according to your project's specific details and requirements.
```

The file should contain one command per line, and the shell will execute them without prompting for input.

## Usage

Once the shell is running, you can enter commands to execute. The shell will attempt to execute the commands using the `execve` system call. If a command is not recognized as a built-in command, it will be treated as an external command and executed accordingly.

In interactive mode, the shell will display a prompt for entering commands. For example:

```
$ ls -l
$ pwd
$ echo "Hello, world!"
```

To exit the shell, you can use the built-in `exit` command or press Ctrl+D.

In batch mode, the shell will read commands from the specified file and execute them without displaying a prompt.

## Contributing

Contributions to the Simple Shell project are welcome! If you have any ideas, suggestions, or bug reports, please open an issue or submit a pull request on GitHub.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgements

This shell implementation was developed as part of a programming exercise. Special thanks to the developers and contributors of the various resources and tutorials that helped in understanding the concepts and techniques involved in building a shell.

## Contact

For any inquiries or questions, feel free to contact us at [email address].
```

Feel free to modify and customize the README file according to your project's specific details and requirements.