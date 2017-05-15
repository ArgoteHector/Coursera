/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.h> 
 * @brief This library includes the functions declarations of the first assesment 
 *
 * <This code includes some statistic functions such as mean, median, max, min and sort>
 *
 * @author <Hector Argote Morales>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

void print_statistics(float stat);
void print_array(unsigned char arr[], unsigned char size);
void sort_array(unsigned char arr[], unsigned char size);

float find_mean(unsigned char arr[], unsigned char size);
unsigned char find_median(unsigned char arr[], unsigned char size);
unsigned char find_minimum(unsigned char arr[], unsigned char size);
unsigned char find_maximum(unsigned char arr[], unsigned char size);


void print_statistics(float stat){
  printf("%f\n",stat);
}

void print_array(unsigned char arr[], unsigned char size){
  unsigned char i;
  for(i = 0; i < size; i++){
    printf("%d",arr[i]);
    printf(" ");
    if( i > 0 && i % 10 == 0 ){
      printf("\n");
    }
  }
  printf("\n");

}

float find_mean(unsigned char arr[], unsigned char size){
  float mean = 0;
  unsigned int i=0;
  for(i = 0; i < size; i++){
    mean += arr[i];
  }
  mean = mean/size;
  return mean;
}

unsigned char find_minimum(unsigned char arr[], unsigned char size){
  unsigned char min = 255;
  unsigned char i;
  for(i = 0; i < size; i++){
    if (min > arr[i]){
        min = arr[i];
    }
  }
  return min;
}

unsigned char find_maximum(unsigned char arr[], unsigned char size){
  unsigned char max = 0;
  unsigned char i;
  for(i = 0; i < size; i++){
    if (max < arr[i]){
        max = arr[i];
    }
  }
  return max;
}

void sort_array(unsigned char arr[], unsigned char size){
  unsigned char i, j, a;
  for(i = 0; i < size; ++i){
    for(j = i+1; j < size; ++j){
      if( arr[i] > arr[j] ){
        a = arr[i];
        arr[i] = arr[j];
        arr[j] = a;
      }
    }
  } 
}

unsigned char find_median(unsigned char arr[], unsigned char size){
  sort_array(arr,size);
  return arr[size/2];
}

#endif /* __STATS_H__ */
