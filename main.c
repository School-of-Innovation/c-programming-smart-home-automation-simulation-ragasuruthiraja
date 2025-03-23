/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

#include <stdio.h>

#define MAX_ROOMS 9 //  max number of rooms

// Function prototypes
void initializeSystem(int lights[],int temp[],int motion[],int locks[],int rooms);
void displayMenu(int lights[], int temp[], int motion[], int locks[], int rooms, int noMotionCounter[], int lightOnCounter[]);
void controlLights(int lights[],int rooms);
void readTemperature(int temp[],int rooms);
void detectMotion(int motion[],int rooms);
void securitySystem(int locks[],int rooms);
void analyzeHouseStatus(int lights[], int temp[], int motion[], int locks[], int rooms);
void autoLockFeature(int motion[], int locks[], int rooms, int noMotionCounter[]);
void temperatureAlert(int temp[], int rooms);
void energySavingMode(int lights[], int rooms, int lightOnCounter[]);

int main() {
    int rooms;
    printf("Enter number of rooms: ");
    scanf("%d", &rooms);
    if (rooms > MAX_ROOMS) rooms = MAX_ROOMS;
    
    int lights[rooms], temp[rooms], motion[rooms], locks[rooms];
    int noMotionCounter[1] = {0}, lightOnCounter[1] = {0};
    
    initializeSystem(lights, temp, motion, locks, rooms);
    displayMenu(lights, temp, motion, locks, rooms, noMotionCounter, lightOnCounter);
    
    return 0;
}

void displayMenu(int lights[], int temp[], int motion[], int locks[], int rooms, int noMotionCounter[], int lightOnCounter[]) {
    int choice;
    do {
        printf("\n===== Smart Home Menu =====\n");
        printf("1. control Light\n");
        printf("2. Read Temperature\n");
        printf("3. Check Motion Sensor\n");
        printf("4. Security System\n");
        printf("5. House Status Summary\n");
        printf("6. Auto-Lock Feature\n");
        printf("7. Temperature Alert System\n");
        printf("8. Energy Saving Mode\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: controlLights(lights, rooms); break;
            case 2: readTemperature(temp, rooms); break;
            case 3: detectMotion(motion, rooms); break;
            case 4: securitySystem(locks, rooms); break;
            case 5: analyzeHouseStatus(lights, temp, motion, locks, rooms); break;
            case 6: autoLockFeature(motion, locks, rooms, noMotionCounter); break;
            case 7: temperatureAlert(temp, rooms); break;
            case 8: energySavingMode(lights, rooms, lightOnCounter); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 9);
}

void initializeSystem(int lights[], int temp[], int motion[], int locks[], int rooms) {
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;
        temp[i] = 22 + (i % 5);
        motion[i] = 0;
        locks[i] = 1;
    }
    printf("System initialized.\n");
} 

void controlLights(int lights[], int rooms) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        lights[room - 1] = !lights[room - 1];
        printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid room number!\n");
    }
}

void readTemperature(int temp[], int rooms) {
    int room;
    printf("Enter room number to read temperature (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        printf("Room %d Temperature: %d°C\n", room, temp[room - 1]);
    } else {
        printf("Invalid room number!\n");
    }
}

void detectMotion(int motion[], int rooms) {
    int room;
    printf("Enter room number to check motion (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        printf("Motion in Room %d: %s\n", room, motion[room - 1] ? "Detected" : "No Motion");
    } else {
        printf("Invalid room number!\n");
    }
} 

void securitySystem(int locks[], int rooms) {
    int room;
    printf("Enter room number to lock/unlock (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        locks[room - 1] = !locks[room - 1];
        printf("Room %d Door is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
    } else {
        printf("Invalid room number!\n");
    }
} 

void analyzeHouseStatus(int lights[], int temp[], int motion[], int locks[], int rooms) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < rooms; i++) {
        printf("- Room %d: Light %s, Temp %d°C, %s, %s\n", i + 1, 
               lights[i] ? "ON" : "OFF", temp[i], 
               motion[i] ? "Motion Detected" : "No Motion", 
               locks[i] ? "Locked" : "Unlocked");
    }
}

void autoLockFeature(int motion[], int locks[], int rooms, int noMotionCounter[]) {
    int motionDetected = 0;
    for (int i = 0; i < rooms; i++) {
        if (motion[i]) motionDetected = 1;
    }
    if (!motionDetected) noMotionCounter[0]++;
    else noMotionCounter[0] = 0;
    
    if (noMotionCounter[0] >= 5) {
        for (int i = 0; i < rooms; i++) locks[i] = 1;
        printf("Auto-Lock Enabled: All doors are now locked.\n");
        noMotionCounter[0] = 0;
    }
}

void temperatureAlert(int temp[], int rooms) {
    for (int i = 0; i < rooms; i++) {
        if (temp[i] > 30) {
            printf("Warning: Room %d Temperature is too high! (%d°C)\n", i + 1, temp[i]);
        }
    }
}

void energySavingMode(int lights[], int rooms, int lightOnCounter[]) {
    int allLightsOn = 1;
    for (int i = 0; i < rooms; i++) {
        if (!lights[i]) allLightsOn = 0;
    }
    if (allLightsOn) lightOnCounter[0]++;
    else lightOnCounter[0] = 0;
    
    if (lightOnCounter[0] >= 3) {
        printf("Energy Saving Mode: Consider turning off some lights to save power.\n");
    }
}
