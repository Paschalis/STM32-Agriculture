#include "main.h"
#include "gpio.h"
#include "tim.h"
#include "usart.h" // Include USART header file for USART1 configuration
#include <stdio.h> // Include stdio.h for printf()
#include <string.h>

// Function prototypes
void SystemClock_Config(void);
void DS18B20_Init(void);
void DS18B20_WriteBit(uint8_t bit);
uint8_t DS18B20_ReadBit(void);
void DS18B20_WriteByte(uint8_t byte);
uint8_t DS18B20_ReadByte(void);
void DS18B20_StartConversion(void);
float DS18B20_ReadTemperature(void);

int main(void)
{
    // MCU Configuration
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_TIM1_Init();
    MX_USART1_UART_Init(); // Initialize USART1 for serial communication

    // Initialize DS18B20 sensor
    DS18B20_Init();

    while (1)
    {
        // Start temperature conversion
        DS18B20_StartConversion();

        // Read temperature
        float temperature = DS18B20_ReadTemperature();

        // Print temperature via USART1
        char buffer[50];
        sprintf(buffer, "Temperature: %.2f C\r\n", temperature);
        HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);

        // Delay before next reading
        HAL_Delay(1000);
    }
}

// System Clock Configuration (auto-generated by STM32CubeIDE)
void SystemClock_Config(void)
{
    // Configure system clock...
}

// Initialize GPIO pin for OneWire communication
void DS18B20_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = GPIO_PIN_15; // PA15
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

// Write a single bit to the DS18B20 sensor
void DS18B20_WriteBit(uint8_t bit)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET); // Pull the bus low

    // Delay to meet the timing requirements of the OneWire protocol
    // You may need to adjust the delay based on your microcontroller clock frequency
    HAL_Delay(5);

    if (bit)
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET); // Release the bus
    }

    // Delay to meet the timing requirements of the OneWire protocol
    HAL_Delay(60);
}

// Read a single bit from the DS18B20 sensor
uint8_t DS18B20_ReadBit(void)
{
    uint8_t bit = 0;

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET); // Pull the bus low

    // Delay to meet the timing requirements of the OneWire protocol
    HAL_Delay(5);

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET); // Release the bus

    // Delay to wait for the DS18B20 to respond
    HAL_Delay(10);

    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == GPIO_PIN_SET)
    {
        bit = 1; // Read logic high
    }

    // Delay to meet the timing requirements of the OneWire protocol
    HAL_Delay(45);

    return bit;
}

// Write a byte of data to the DS18B20 sensor
void DS18B20_WriteByte(uint8_t byte)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        DS18B20_WriteBit(byte & 0x01); // Write LSB first
        byte >>= 1; // Shift byte right by 1 bit
    }
}

// Read a byte of data from the DS18B20 sensor
uint8_t DS18B20_ReadByte(void)
{
    uint8_t byte = 0;

    for (uint8_t i = 0; i < 8; i++)
    {
        byte >>= 1; // Shift byte right by 1 bit
        byte |= (DS18B20_ReadBit() << 7); // Read MSB first
    }

    return byte;
}

// Start temperature conversion on the DS18B20 sensor
void DS18B20_StartConversion(void)
{
    DS18B20_Init();
    DS18B20_WriteByte(0xCC); // Skip ROM command
    DS18B20_WriteByte(0x44); // Start conversion command
}

// Read temperature from the DS18B20 sensor
float DS18B20_ReadTemperature(void)
{
    DS18B20_Init();
    DS18B20_WriteByte(0xCC); // Skip ROM command
    DS18B20_WriteByte(0xBE); // Read Scratchpad command

    uint8_t temp_LSB = DS18B20_ReadByte();
    uint8_t temp_MSB = DS18B20_ReadByte();
    int16_t temp_raw = (temp_MSB << 8) | temp_LSB;

    // Convert raw temperature to Celsius
    float temperature = (float)temp_raw / 16.0;

    return temperature;
}

// Error handler (auto-generated by STM32CubeIDE)
void Error_Handler(void)
{
    while (1)
    {
    }
}

// Assert failed handler (auto-generated by STM32CubeIDE)
void assert_failed(uint8_t *file, uint32_t line)
{
}