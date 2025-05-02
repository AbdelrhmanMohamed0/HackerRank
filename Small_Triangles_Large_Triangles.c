#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;
float get_area(triangle *arr, int i)
{
    float p = ((arr[i].a + arr[i].b + arr[i].c) / 2.0);
    float s = sqrt(p * (p - arr[i].a) * (p - arr[i].b) * (p - arr[i].c));
    return s;
}
void swap(triangle *tr, int i, int j)
{
    tr[i].a = tr[i].a ^ tr[j].a;
    tr[j].a = tr[i].a ^ tr[j].a;
    tr[i].a = tr[i].a ^ tr[j].a;
    tr[i].b = tr[i].b ^ tr[j].b;
    tr[j].b = tr[i].b ^ tr[j].b;
    tr[i].b = tr[i].b ^ tr[j].b;
    tr[i].c = tr[i].c ^ tr[j].c;
    tr[j].c = tr[i].c ^ tr[j].c;
    tr[i].c = tr[i].c ^ tr[j].c;
}
void sort_by_area(triangle *tr, int n)
{
    float *arr = malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
    {
        arr[i] = get_area(tr, i);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(tr, i, j);
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    free(arr);
}

int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}





//another way 
/*

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

float get_area(triangle t) {
    float p = (t.a + t.b + t.c) / 2.0;
    return sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
}


int compare(const void* a, const void* b) {
    triangle* t1 = (triangle*)a;
    triangle* t2 = (triangle*)b;
    
    float area1 = get_area(*t1);
    float area2 = get_area(*t2);
    
    if (area1 > area2) return 1;    
    else if (area1 < area2) return -1; 
    else return 0;                    
}

void sort_by_area(triangle* tr, int n) {
    qsort(tr, n, sizeof(triangle), compare);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
*/