# GetNextLine
The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor.

## int get_next_line(inf fd, char **line)
+ Calling your function get_next_line in a loop will then allow you to read the text available on a file descriptor one line at a time until the EOF.

## Bonus
+ To succeed get_next_line with a single static variable.
+ To be able to manage multiple file descriptor with your get_next_line. For example,if the file descriptors 3, 4 and 5 are accessible for reading, then you can call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors.

## Tester
- [42TESTERS-GNL](https://github.com/Mazoise/42TESTERS-GNL)
- [gnlkiller](https://github.com/DontBreakAlex/gnlkiller)
- [42cursus_gnl_tests](https://github.com/mrjvs/42cursus_gnl_tests)
- [GNL_lover](https://github.com/charMstr/GNL_lover)
- [gnl-war-machine-v2019](https://github.com/Alexandre94H/gnl-war-machine-v2019)

## What needs to be improved
+ The buffer should be dynamically allocated.
+ The get_next_line() must return -1 if memory allocation fails.
