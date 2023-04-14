#include <stdio.h>
#include <stdlib.h>

void print_matrix(int arr[5][5]){
for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n\n");
    }
}

void swap_pos(int arr[5][5],int i,int j,int k,int z){
   int temp;
   temp=arr[i][j];
   arr[i][j]=arr[k][z];
   arr[k][z]=temp;
}

void rotate_matrix90degrees(int arr[5][5])
{
  swap_pos(arr,0,0,0,4);
  swap_pos(arr,0,0,4,4);
  swap_pos(arr,0,0,4,0);
  swap_pos(arr,0,1,1,4);
  swap_pos(arr,0,1,4,3);
  swap_pos(arr,0,1,3,0);
  swap_pos(arr,0,2,2,4);
  swap_pos(arr,0,2,4,2);
  swap_pos(arr,0,2,2,0);
  swap_pos(arr,0,3,3,4);
  swap_pos(arr,0,3,4,1);
  swap_pos(arr,0,3,1,0);
  swap_pos(arr,1,1,1,3);
  swap_pos(arr,1,1,3,3);
  swap_pos(arr,1,1,3,1);
  swap_pos(arr,1,2,2,3);
  swap_pos(arr,1,2,3,2);
  swap_pos(arr,1,2,2,1);
}

void search_vector_size1(int arr[5][5],int input){
    int correction=0;
for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(arr[i][j]==input){
                printf("The vector you are seeking is at %d,%d\n",i,j);
                correction++;
            }
        }
    }
    if(correction==0){
    puts("Not found!");
    }
}
void search_vector_size2(int arr[5][5],int input1,int input2){
       int correction=0;
for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(arr[i][j]==input1 && arr[i][j+1]==input2){
                printf("The vector you are seeking is at %d,%d\n",i,j);
                correction++;
            }
        }
    }
    if(correction==0){
    puts("Not found!");
    }
}
void search_vector_size3(int arr[5][5],int input1,int input2,int input3){
               int correction=0;
for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(arr[i][j]==input1 && arr[i][j+1]==input2&&arr[i][j+2]==input3){
                printf("The vector you are seeking is at %d,%d\n",i,j);
                correction++;
            }
        }
    }
    if(correction==0){
    puts("Not found!");
    }
}
void search_vector_size4(int arr[5][5],int input1,int input2,int input3,int input4){
        int correction=0;
for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(arr[i][j]==input1 && arr[i][j+1]==input2&&arr[i][j+2]==input3&&arr[i][j+3]==input4){
                printf("The vector you are seeking is at %d,%d\n",i,j);
                correction++;
            }
        }
    }
    if(correction==0){
    puts("Not found!");
    }
}
void search_vector_size5(int arr[5][5],int input1,int input2,int input3,int input4,int input5){
        int correction=0;
for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(arr[i][j]==input1 && arr[i][j+1]==input2&&arr[i][j+2]==input3&&arr[i][j+3]==input4&&arr[i][j+4]==input5){
                printf("The vector you are seeking is at %d,%d\n",i,j);
                correction++;
            }
        }
    }
    if(correction==0){
    puts("Not found!");
    }
}


void main()
{
    int matrix[5][5] = {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34};
    int choice;
    int rotatedegree,vectorL,vector[5];
    do{
        puts("What do you want to do?\n 1: Rotate the matrix clockwise\n 2:Search a vector within the matrix\n 3:Exit the program\n");
        scanf("%d",&choice);
        switch(choice){
    case 1:
    puts("The matrix is:\n");
    print_matrix(matrix);
    rotationidentification:
    puts("How many degrees do you want it to rotate?");
    scanf("%d",&rotatedegree);
     if(rotatedegree==90){
    rotate_matrix90degrees(matrix);
    print_matrix(matrix);
    break;
     }if(rotatedegree==180){
    rotate_matrix90degrees(matrix);
    rotate_matrix90degrees(matrix);
    print_matrix(matrix);
    break;
     }if(rotatedegree==270){
    rotate_matrix90degrees(matrix);
    rotate_matrix90degrees(matrix);
    rotate_matrix90degrees(matrix);
    print_matrix(matrix);
    break;
     }if(rotatedegree!=90||rotatedegree!=180||rotatedegree!=270){
     puts("Please enter 90 180 or 270\n");
     goto rotationidentification;
     }
        break;
    case 2:
    printf("The matrix is:\n");
    print_matrix(matrix);
    vectoridentification:
    puts("How long will the vector will be?");
    scanf("%d",&vectorL);
    if(vectorL<6 && vectorL>0){
    puts("Enter the vector\n");
    for(int i=0;i<vectorL;i++){
        scanf("%d",&vector[i]);
    }
    }
    else{
        puts("Please enter a number between 1 and 5");
        goto vectoridentification;
    }
    switch(vectorL){
    case 1:
        search_vector_size1(matrix,vector[0]);
        break;
    case 2:
        search_vector_size2(matrix,vector[0],vector[1]);
        break;
    case 3:
        search_vector_size3(matrix,vector[0],vector[1],vector[2]);
        break;
    case 4:
        search_vector_size4(matrix,vector[0],vector[1],vector[2],vector[3]);
        break;
    case 5:
        search_vector_size5(matrix,vector[0],vector[1],vector[2],vector[3],vector[4]);
        break;
    default:
        puts("Please enter a number between 1 and 5");
        break;
    }
            break;
    case 3:
        return 0;
        break;
    default :
        puts("Please enter a number between 1 and 3");
        break;
    }
    }while(choice!=3);
}
