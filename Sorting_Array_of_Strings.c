
/*
i/p

4
wkue
qoi
sbv
fekls

o/p

fekls
qoi
sbv
wkue

wkue
sbv
qoi
fekls

qoi
sbv
wkue
fekls

qoi
sbv
wkue
fekls


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char *a, const char *b)
{
    int state = -1;
    int len1 = strlen(a);
    int len2 = strlen(b);
    int min = (len2 < len1) ? len2 : len1;
    for (int i = 0; i < min; i++)
    {
            if (a[i] > b[i])
            {
                state=1;
                break;
            }
            else if(a[i] == b[i]) 
            {
                if(min==len1)
                {
                state=0;
                }
                else if(min == len2)
                {
                state=1;
                }
            }
            else
            {
                state=0;
                break;
            }
    }
    return state;
}

int lexicographic_sort_reverse(const char *a, const char *b)
{
    int state = -1;
    int len1 = strlen(a);
    int len2 = strlen(b);
    int min = (len2 < len1) ? len2 : len1;
    for (int i = 0; i < min; i++)
    {
            if (a[i] < b[i])
            {
                state=1;
                break;
            }
            else if(a[i] == b[i]) 
            {
                if(min==len2)
                {
                state=0;
                }
                else if(min == len1)
                {
                state=1;
                }
            }
            else
            {
                state=0;
                break;
            }
    }
    return state;
}

// Compare function for sort by number of distinct characters
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_a = 0, count_b = 0;
    int char_count_a[256] = {0}, char_count_b[256] = {0};
    
    // Count number of distinct characters in string a
    for (int i = 0; i < strlen(a); i++) {
        if (char_count_a[(int)a[i]] == 0) {
            char_count_a[(int)a[i]]++;
            count_a++;
        }
    }
    
    // Count number of distinct characters in string b
    for (int i = 0; i < strlen(b); i++) {
        if (char_count_b[(int)b[i]] == 0) {
            char_count_b[(int)b[i]]++;
            count_b++;
        }
    }
    
    if (count_a == count_b) {
        return strcmp(a, b);
    } else if (count_a < count_b) {
        return -1;
    } else {
        return 1;
    }
}

int sort_by_length(const char *a, const char *b)
{
    int state = 0;
    int len1 = 0, len2 = 0;
    len1 = strlen(a);
    len2 = strlen(b);
    if (len1 > len2)
    {
        state = 1;
    }
    else if (len1 == len2)
    {
        state = lexicographic_sort(a, b);
    }
    return state;
}

void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b))
{
    char *str_temp;
    for (int i = 0; i < len-1; i++)
    {
        for(int j=i+1; j<len; j++){
            if (cmp_func(arr[i], arr[j]))
            {
                str_temp= arr[i];
                arr[i]= arr[j];
                arr[j]= str_temp;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);

    char **arr;
    arr = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}




//or

/*

// Compare function for lexicographic sort
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

// Compare function for reverse lexicographic sort
int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

// Compare function for sort by number of distinct characters
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_a = 0, count_b = 0;
    int char_count_a[256] = {0}, char_count_b[256] = {0};
    
    // Count number of distinct characters in string a
    for (int i = 0; i < strlen(a); i++) {
        if (char_count_a[(int)a[i]] == 0) {
            char_count_a[(int)a[i]]++;
            count_a++;
        }
    }
    
    // Count number of distinct characters in string b
    for (int i = 0; i < strlen(b); i++) {
        if (char_count_b[(int)b[i]] == 0) {
            char_count_b[(int)b[i]]++;
            count_b++;
        }
    }
    
    if (count_a == count_b) {
        return strcmp(a, b);
    } else if (count_a < count_b) {
        return -1;
    } else {
        return 1;
    }
}

// Compare function for sort by length
int sort_by_length(const char* a, const char* b) {
    if (strlen(a) == strlen(b)) {
        return strcmp(a, b);
    } else if (strlen(a) < strlen(b)) {
        return -1;
    } else {
        return 1;
    }
}

// Sort function that takes an array of strings and a comparison function
void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    // Sort the array using the comparison function
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (cmp_func(arr[i], arr[j]) > 0) {
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
// Compare function for lexicographic sort
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

// Compare function for reverse lexicographic sort
int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

// Compare function for sort by number of distinct characters
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_a = 0, count_b = 0;
    int char_count_a[256] = {0}, char_count_b[256] = {0};
    
    // Count number of distinct characters in string a
    for (int i = 0; i < strlen(a); i++) {
        if (char_count_a[(int)a[i]] == 0) {
            char_count_a[(int)a[i]]++;
            count_a++;
        }
    }
    
    // Count number of distinct characters in string b
    for (int i = 0; i < strlen(b); i++) {
        if (char_count_b[(int)b[i]] == 0) {
            char_count_b[(int)b[i]]++;
            count_b++;
        }
    }
    
    if (count_a == count_b) {
        return strcmp(a, b);
    } else if (count_a < count_b) {
        return -1;
    } else {
        return 1;
    }
}

// Compare function for sort by length
int sort_by_length(const char* a, const char* b) {
    if (strlen(a) == strlen(b)) {
        return strcmp(a, b);
    } else if (strlen(a) < strlen(b)) {
        return -1;
    } else {
        return 1;
    }
}

// Sort function that takes an array of strings and a comparison function
void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    // Sort the array using the comparison function
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (cmp_func(arr[i], arr[j]) > 0) {
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

*/