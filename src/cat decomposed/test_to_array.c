#include <stdio.h>
#include <stdlib.h>

char* read_text_file(const char *filename) {
    
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Cannot open file \n");
        return NULL;
    }

    // Get the file size
    fseek(file, 0L, SEEK_END);
    long file_size = ftell(file); //returns cursor position
    rewind(file); //курсор в начало
    
    // Allocate the array, including space for the end marker
    char *buffer = (char*)malloc(sizeof(char) * (file_size + 1));
    if (buffer == NULL) {
        printf("Memory allocation failed \n");
        fclose(file);
        return NULL;
    }

    // Read file contents into buffer
    size_t result = fread(buffer, 1, file_size, file);
    if (result != file_size)
    {
        printf("Reading error \n");
        fclose(file);
        return NULL;
    }

    // Null terminate the text
    buffer[file_size] = '\0';

    // Close file
    fclose(file);
    
    return buffer;
}

int main() {
    const char *filename = "test.txt";
    
    // Read the file and store the contents in the array.
    char *content = read_text_file(filename);
    if (content != NULL) {
        printf("File content:\n%s\n", content);
        
        // Free memory
        free(content);
    }
    
    return 0;
}
