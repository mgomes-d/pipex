This project deepened my understanding of UNIX pipes and process management by implementing a simplified shell-like pipeline in C. It emphasized inter-process communication, file handling, and error management, giving me practical experience with low-level system programming.

Approach & main achievements

    • Developed a C program that reproduces the shell command:
	< file1 cmd1 | cmd2 > file2
    • Implemented proper argument parsing to handle input/output files and shell commands
    • Used UNIX system calls: open, close, read, write, dup, dup2, execve, fork, pipe, wait, waitpid
    • Handled errors gracefully, matching the behavior of the shell pipeline
    • Managed memory efficiently, avoiding leaks and unexpected crashes
    • Created a Makefile following 42 norms with standard targets (all, clean, fclean, re)
    • Supported multiple pipes: < file1 cmd1 | cmd2 | ... | cmdn > file2
    • Implemented here_doc functionality: cmd << LIMITER | cmd1 >> file





Technical environment & methodologies

    • C programming (low-level UNIX programming)
    • UNIX process management and inter-process communication
    • File handling and I/O redirection
    • Memory management with malloc and free
    • Error handling consistent with shell behavior
    • Makefile creation and project structuring according to 42 Norm
