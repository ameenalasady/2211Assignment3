#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the array, its size in bytes and number of elements
void partOne(int *arr, int n)
{
    printf("\nPart 1:\n");
    printf("\tYour array is: ");

    // Loop to print the array
    for (int i = 0; i < n; i++)
    {
        printf("[%d] = %d, ", i, arr[i]);
    }

    // Calculate and print the size of the array in bytes
    printf("\n\tThe size of the array is %d bytes", n * sizeof(int));

    // Print the number of elements in the array
    printf("\n\tYour array has %d elements", n);
}

// Function to print the array in reverse order
void partTwo(int *arr, int n)
{
    printf("\n\nPart 2:");
    printf("\n\tYour array in reverse is: ");

    // Loop to print the array in reverse order
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
}

// Function to find and print the largest value in the array
void partThree(int *arr, int n)
{
    printf("\n\nPart 3:");

    // Check if array is empty
    if (n == 0)
    {
        printf("\n\tYour array is empty.");
        return;
    }

    int largest = arr[0];

    // Loop to find the largest value in the array
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    // Print the largest value in the array
    printf("\n\tThe largest value in your array is: %d", largest);
}

// Function to calculate and print the sum of all values in the array
void partFour(int *arr, int n)
{
    printf("\n\nPart 4:");

    int sum = 0;

    // Loop to calculate the sum of all values in the array
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    // Print the sum of all values in the array
    printf("\n\tThe sum of all values in your array is: %d", sum);
}

// Function to switch first and last element of the array and print it
void partFive(int *arr, int n)
{
    printf("\n\nPart 5:");

    // Check if array has less than two elements
    if (n < 2)
    {
        printf("\n\tYour array has less than two elements.");
        return;
    }

    printf("\n\tYour array with first and last element switched is: ");

    // Print last element of the array
    printf("%d ", arr[n - 1]);

    // Loop to print elements between first and last element
    for (int i = 1; i < n - 1; i++)
    {
        printf("%d ", arr[i]);
    }

    // Print first element of the array
    printf("%d ", arr[0]);
}

// Function to sort and print the array in ascending order
void partSix(int *arr, int n)
{
    printf("\n\nPart 6:");

    // Create a copy of the original array
    int *copy = malloc(n * sizeof(int));
    memcpy(copy, arr, n * sizeof(int));

    // Sort copy of original array using bubble sort algorithm
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (copy[i] > copy[j])
            {
                int temp = copy[i];
                copy[i] = copy[j];
                copy[j] = temp;
            }
        }
    }

    // Print sorted copy of original array
    printf("\n\tYour array in sorted order is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", copy[i]);
    }
    printf("\n");

    // Free memory allocated for copy of original array
    free(copy);
}

int main(int argc, char const *argv[])
{
    int numberOfElements;

    // Prompt user to enter number of elements in their array
    printf("Please enter how many integers are in your array: ");
    scanf("%d", &numberOfElements);

    // Check if number of elements entered by user is non-negative
    if (numberOfElements < 0)
    {
        printf("Number of elements cannot be negative.\n");
        return -1;
    }

    // Allocate memory for user's array
    int *arr = (int *)malloc(numberOfElements * sizeof(int));

    // Prompt user to enter elements of their array
    printf("Please enter your %d integer(s) separated by spaces: ", numberOfElements);
    for (int i = 0; i < numberOfElements; i++)
    {
        scanf(" %d", &arr[i]);
    }

    // Call functions to perform various operations on user's array
    partOne(arr, numberOfElements);
    partTwo(arr, numberOfElements);
    partThree(arr, numberOfElements);
    partFour(arr, numberOfElements);
    partFive(arr, numberOfElements);
    partSix(arr, numberOfElements);

    // Free memory allocated for user's array, avoiding memory leaks
    free(arr);
}