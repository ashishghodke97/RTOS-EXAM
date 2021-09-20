#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
QueueHandle_t xQ1;
void T1(void *data)
{
	while(1)
	{


	printf("Task (T1) started\n");
	
	printf("Task (T1) ended\n");
	vTaskDelay(1000/portTICK_PERIOD_MS);
	}
}
void T1(void *data)
{
	while(1)
	{


	printf("Task (T2) started\n");
	
	printf("Task (T2) ended\n");
	vTaskDelay(2000/portTICK_PERIOD_MS);
}
	
}
void T3(void *data)
{
	while(1)
	{

	
	printf("Task (T3) started\n");
	
	printf("Task (T3) ended\n");
	vTaskDelay(5000/portTICK_PERIOD_MS);
	}
}
void T4(void *data)
{
int var=10;
while(1)
{
		xQueueSend(xQueue1,&var,0);
		vTaskDelay(3000/portTICK_PERIOD_MS);
}
}

 void T5(void *data)
 {
 	while(1)
 	{


 		int buff;
 		xQueueReceive(xQueue1,&buff,0);
 		
 			printf("In Task 5 received message from Task 4 is %d\n",buff);
 		vTaskDelay(3000/portTICK_PERIOD_MS);
 	}
 }
void app_main(void)
	{
		xTaskCreate(T1,"Task_1",2048,NULL,10,NULL);
		xTaskCreate(T2,"Task_2",2048,NULL,6,NULL);
		xTaskCreate(T3,"Task_3",2048,NULL,5,NULL);
		xTaskCreate(T4,"Task_4",2048,NULL,3,NULL);
		xTaskCreate(T5,"Task_5",2048,NULL,1,NULL);
		xQueue1= xQueueCreate(3,sizeof(int));
	}
