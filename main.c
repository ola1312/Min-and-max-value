#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const size_t INIT_SIZE = 5;

void min_max (float data[], size_t n, float *min_value, float *max_value)
{
float min = data[0];
float max = data[0];
for (int i= 1; i< n ; i++)
  { 
    if (min > data[i])
      min = data[i];
    else if (max < data[i])
      max = data[i];
  }
*min_value = min;
*max_value = max;
}

int main(void)
{
  size_t size = INIT_SIZE;
  float *data = (float*) calloc (sizeof(float), size);
  if (!data)
    {
      fputs ("Blad alokacji pamieci!", stderr);
      return 1;
    }
  
  int i = 0;
  while (!feof (stdin))
  {
    if(i >= size)
    {
      size = size + INIT_SIZE;
      data = (float*) realloc (data, size * sizeof(float));
    }
    scanf("%f\n", &data[i]);
    i++;
  }
  size = i;
  data = (float*) realloc (data, size * sizeof(float));

  float min, max;
  min_max(data, size, &min, &max);
  printf("Wczytano %ld liczb, z których wartość minimalna wynosi %.3f, a maksymalna %.3f\n", size, min, max);
  
  free(data);
  return 0;
}