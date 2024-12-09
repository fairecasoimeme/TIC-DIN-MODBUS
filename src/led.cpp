#include <Arduino.h>
#include "led.h"

#define LED_PIN 3

extern uint8_t u8ErrorDecode;

// Handle de tâche pour contrôler la tâche plus tard
TaskHandle_t handleBlinkTask = NULL;



void blinkLedTask(void *pvParameters) {
    
    //int *delayBlink = (int *)pvParameters;
    int delayBlink = 500;
    // Configuration de la pin LED comme sortie
    pinMode(LED_PIN, OUTPUT);
    
    while (1) {

        if (u8ErrorDecode >0)
        {
            delayBlink = 1000;
        }else{
            delayBlink = 3000;
        }

        // Allumer la LED
        digitalWrite(LED_PIN, HIGH);
        // Attendre 500 millisecondes
        vTaskDelay(pdMS_TO_TICKS(500));
        
        // Éteindre la LED
        digitalWrite(LED_PIN, LOW);
        // Attendre encore 500 millisecondes
        vTaskDelay(pdMS_TO_TICKS(delayBlink));
    }
}

/*void startBlink(int millisecond)
{
     // Créer la tâche de clignotement de la LED
    if (handleBlinkTask!= NULL) 
    {
        stopBlink();
    }
    xTaskCreate(
        blinkLedTask,     // La fonction qui implémente la tâche
        "Blink LED Task", // Nom de la tâche (pour débogage)
        1024,             // Taille de la pile pour la tâche
        (void *)&millisecond,             // Paramètre pour la tâche
        5,                // Priorité de tâche
        &handleBlinkTask             // Handle de tâche (optionnel)
    );   
}*/

void stopBlink()
{
    vTaskDelete(handleBlinkTask);
}

void initLed()
{
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN,LOW);

    xTaskCreate(blinkLedTask,"TaskLed",1024,NULL,1,NULL);
}