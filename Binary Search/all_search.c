#include <stdio.h>
int linear_search(int[], int, int);
int binary_search_iterative(int[], int, int, int);
int binary_search_recursive(int[], int, int, int);
void searching_result(int);
void main()
{
    int a[100], n, i, key, x, j, c;
    printf("\n enter size of array: ");
    scanf("%d", &n);
    printf("\n enter the elements in the array in sorted order.....\n");
    for (i = 0; i < n; i++)
    {
        printf("\n enter the data into a[%d] : ", i);
        scanf("%d", &a[i]);
    }
    j = 1;
    while (j)
    {
        printf("\n enter data which is to be search : ");
        scanf("%d", &key);
        printf("\n\n *******menu bar******\n");
        printf("\n\t 1: linear search ");
        printf("\n\t 2: Binary iterative search ");
        printf("\n\t 1: Binary recursive search ");
        printf("\n\n ********************\n ");
        printf("\n enter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            x = linear_search(a, n, key);
            searching_result(x);
            break;
        case 2:
            x = binary_search_iterative(a, 0, n - 1, key);
            searching_result(x);
            break;

        case 3:
            x = binary_search_recursive(a, 0, n - 1, key);
            searching_result(x);
            break;
        }
        printf("\n press 1 to continue, otherwise press 0 : ");
        scanf("%d", &j);
    }
}
void searching_result(int x)
{
    if (x == -1)
    {
        printf("\n search unsuccessful....");
    }
    else
    {
        printf("\n search successful in the position %d", x + 1);
    }
}
int linear_search(int a[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int binary_search_iterative(int a[], int lb, int ub, int key)
{
    int mid;
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (key > a[mid])
        {
            lb = mid + 1;
        }
        else
        {
            ub = mid - 1;
        }
    }
    return -1;
}
int binary_search_recursive(int a[], int lb, int ub, int key)
{
    int mid;
    if (lb > ub)
    {
        return -1;
    }
    else
    {
        mid = (lb + ub) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (key > a[mid])
        {
            return binary_search_recursive(a, mid + 1, ub, key);
        }
        else
        {
            binary_search_recursive(a, lb, mid - 1, key);
        }
    }
}