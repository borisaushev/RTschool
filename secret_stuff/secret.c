#include <assert.h>
#include <string.h>
#include <unistd.h>

#include "../input/input.h"
#include "secret.h"

int arsenUltrakill() {
    sleep(1);
    printf("Ты любишь Арсена?\n");
    sleep(1);
    printf("А он тебя нет\n");
    sleep(2);
    system("nircmd.exe mutesysvolume 0");
    system("nircmd.exe setsysvolume 65535");
    system("start wmplayer.exe \"C:\\Users\\bossb\\Downloads\\sanya.mp3\"");
    sleep(1);
    //https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR6vdxd37X4M2sCz8PXbOVTe7-h9GUWmjTBtw&s
    //https://m.vk.com/photo-194944166_457642232?rev=1
    for (int i = 0; i < 30; i++) {
        system("start msedge --start-fullscreen \"https://avatars.mds.yandex.net/i?id=5c4f760e8659f711e41dc25a777058ab-5232402-images-thumbs&n=13\"");
    }
    sleep(3);
    system("start wmplayer.exe \"C:\\Users\\bossb\\Downloads\\stereomadness.mp3\"");

    sleep(4);
    system("nircmd.exe mutesysvolume 0");
    system("nircmd.exe setsysvolume 65535");
    system("start wmplayer.exe \"C:\\Users\\bossb\\Downloads\\sanya.mp3\"");

    return 0;
}

int scary() {
    //скример
    //system("taskkill /IM wmplayer.exe /F");
    sleep(2);
    printf("Считать умеешь?\n");
    sleep(2);
    printf("Считай это говно\n");
    sleep(2);
    printf("** *** ** *** **\n");
    sleep(1);
    printf("Сколько?\n");
    sleep(3);

    system("nircmd.exe mutesysvolume 0");
    system("nircmd.exe setsysvolume 65535");
    system("start wmplayer.exe /fullscreen \"C:\\Users\\bossb\\Downloads\\congrats.mp4\"");

    return 0;
}

int reveal() {
    sleep(4);
    printf("-Здраствуйте я тут сделал посмотрите пж\n");
    sleep(3);
    printf("Че ты там сделал\n");
    sleep(3);
    printf("-Я добавил структуры\n");
    sleep(2);
    printf("Иди разбивай на файлы\n");
    sleep(2);
    printf("-А я не знаю как\n");
    sleep(2);
    printf("Иди гугли\n");
    sleep(2);
    printf("Знаешь кто так говорит?(Да/Нет)\n");
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, stdin);

    if (!strcmp(line, "Нет\n")) {
        printf("Пидора ответ\n");
    }
    else if (!strcmp(line, "Да\n")) {
        printf("Пизда\n");
    }
    sleep(1);
    printf("3\n");
    sleep(1);
    printf("2\n");
    sleep(1);
    printf("1\n");
    sleep(1);
    printf("...\n");
    sleep(1);

    system("\"C:\\Program Files\\WindowsApps\\Microsoft.WindowsCamera_2025.2505.2.0_x64__8wekyb3d8bbwe\\WindowsCamera.exe\"");

    printf("\nСам гугли\n");

    return 0;
}

int doSecretGangsterShit(const char secretCommand[]) {
    if (strcmp(secretCommand, "arsen_sigma\n") == 0) {
        arsenUltrakill();
    }
    else if (strcmp(secretCommand, "accept_your_destiny\n") == 0) {
        scary();
    }
    else if (strcmp(secretCommand, "sinners_fate\n") == 0) {
        reveal();
    }
    else {
        printf("invalid secret command\n");
        assert(0);
    }

    return 0;
}
