# Flashing STM32 Microcontroller Code
You can use either an **ST-Link programmer** or the **micro-USB port** on the STM32 board to program and flash the code onto the STM32 microcontroller. 

Here's how you can do it with each method:

## Using an ST-Link Programmer:

1. Connect your ST-Link programmer to your computer via USB.
2. Connect the ST-Link programmer to the SWD pins (SWDIO, SWCLK) on your STM32 board.
3. Open your STM32 IDE (e.g., STM32CubeIDE).
4. Build your project to compile the code.
5. Click on "Run" or "Debug" to flash the compiled binary onto the STM32 microcontroller using the ST-Link programmer.

## Upgrade Instructions

## Connecting the Device to Linux

1. Connect the device to your Linux system using an appropriate USB cable.

## Checking Device Connection

1. Open a terminal on your Linux system.

2. Use the `lsusb` command to list USB devices:

lsusb

markdown


3. Look for the device in the list. Note down its vendor and product ID.

## Probing Device Information

1. In the terminal, use the following command to probe device information:

st-info --probe

## Using the Micro-USB Port on the STM32 Board:

1. Connect your STM32 board to your computer via the micro-USB port.
2. Ensure that the micro-USB port is configured for USB communication (e.g., USB CDC).
3. Open your STM32 IDE (e.g., STM32CubeIDE).
4. Build your project to compile the code.
5. Click on "Run" or "Debug" to flash the compiled binary onto the STM32 microcontroller.
6. The IDE should automatically detect the connected STM32 board via USB and flash the code onto it.

Using the **micro-USB port** on the STM32 board for programming is convenient and eliminates the need for an external programmer like the ST-Link. However, make sure that your STM32 board supports USB programming and that the appropriate bootloader is installed if necessary.

If you're using an STM32 development board like the STM32F103C8T6 (commonly referred to as the "Blue Pill"), it typically supports USB programming via the built-in bootloader, allowing you to program it directly through the micro-USB port.

Choose the method that best suits your setup and preferences.
