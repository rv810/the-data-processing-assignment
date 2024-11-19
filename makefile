clean: clean.c clean_data.c format_IO.c clean_data.h format_IO.h
	gcc -o clean clean.c clean_data.c format_IO.c clean_data.h format_IO.h