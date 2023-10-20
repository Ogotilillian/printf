#include "main.h"

int _printf(const char *format, ...)
{
	    va_list bingoo;
int count = 0;
     char buffer[BUFFER_SIZE];
          int buffer_index = 0;
	    va_start(bingoo, format);


    while (*format) {
        if (*format != '%') {
            if (buffer_index < BUFFER_SIZE - 1) {
                buffer[buffer_index] = *format;
                buffer_index++;
            } else {
                buffer[BUFFER_SIZE - 1] = '\0';
                write(1, buffer, buffer_index);
                buffer_index = 0;
                buffer[buffer_index] = *format;
                buffer_index++;
            }
            count++;
        } else {
            format++;
            switch (*format) {
                case 'C':
                    count += print_nairobi_string(bingoo);
                    break;
                case 'c':
                    count += print_mombasa_char(bingoo);
                    break;
                case 'P':
                    count += print_dodoma_percent(bingoo);
                    break;
                default:
    
                    if (buffer_index < BUFFER_SIZE - 2) {
                        buffer[buffer_index] = '%';
                        buffer_index++;
                        buffer[buffer_index] = *format;
                        buffer_index++;
                    } else {
                        buffer[BUFFER_SIZE - 2] = '%';
                        buffer[BUFFER_SIZE - 1] = *format;
                        write(1, buffer, buffer_index);
                        buffer_index = 0;
                    }
                    count += 2;
            }
        }
        format++;
    }


    if (buffer_index > 0) {
        buffer[buffer_index] = '\0';
	write(1, buffer, buffer_index);
    }

    va_end(bingoo);
    return count;
}
