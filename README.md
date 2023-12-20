The get_next_line function reads one line from a file and returns it, or NULL in case of an error (end of file, problem with the read function...).
A leak was possible in my previous implementation, when the file wasn't read all the way through. Therefore I added a binary parameter in my get_next_line function to account for that.
If said parameter is set to one, then the static variable will be freed, and null will be returned. Otherwise the function will be implemented as usual.

Therefore, please note that the parameters of my get_next_line are not the ones from the subject, I added a binary parameter to allow me to free my static variable if I ever do not need to read all the file
