//!@file

#include <assert.h>
#include <string.h>
#include <unistd.h>

#include "square_solver/input/input.h"
#include "commands.h"

#include "square_solver/squareSolver.h"

/**
 * unmutes the system and sets the volume to max value
 * @return zero if all fine
 */
int setMaxVolume() {
    system(UNMUTE_COMMAND);
    system(MAX_VOLUME_COMMAND);

    return 0;
}

/**
 * plays given sound by path
 * @param soundPath path to .mp3 file
 * @return zero if all fine
 */
int playSound(const char *soundPath) {
    char command[MAX_LINE_LENGTH];
    snprintf(command, sizeof(command), "%s%s", SOUND_PLAYER_COMMAND, soundPath);
    system(command);

    return 0;
}

/**
 * plays given video by path
 * @param videoPath path to video
 * @return zero if all fine
 */
int playVideo(const char *videoPath) {
    char command[MAX_LINE_LENGTH];
    snprintf(command, sizeof(command), "%s%s", VIDEO_PLAYER_COMMAND, videoPath);
    system(command);

    return 0;
}

/**
 * opens given link in Microsoft Edge
 * @param link browser link
 * @return zero if all fine
 */
int openLink(const char* link) {
    char command[MAX_LINE_LENGTH];
    snprintf(command, sizeof(command), "%s%s", EDGE_COMMAND, link);
    system(command);

    return 0;
}

/**
 * executes arsen_sigma command
 * @return zero if all fine
 */
int arsen() {
    sleep(1);
    printf("Ты любишь Арсена?\n");
    sleep(1);
    printf("А он тебя нет\n");
    sleep(2);

    setMaxVolume();
    playSound(MOANS_SOUND_PATH);
    sleep(1);
    for (int i = 0; i < TABS_COUNT; i++) {
        openLink(HOG_IMAGE_LINK);
    }

    sleep(3);
    playSound(STEREO_MADNESS_SOUND_PATH);

    sleep(4);
    setMaxVolume();
    playSound(MOANS_SOUND_PATH);

    return 0;
}

/**
 * executes count_the_stars comment
 * @return zero if all fine
 */
int countTheStars() {
    //скример
    sleep(1);
    printf("Считать умеешь?\n");
    sleep(2);
    printf("Считай звезды\n");
    sleep(2);
    printf("** *** ** *** *** *** *\n");
    sleep(1);
    printf("Сколько?\n");
    sleep(3);

    setMaxVolume();
    playVideo(SCREAMER_VIDEO_PATH);

    return 0;
}


/**
 * starts camera
 * @return zero if all fine
 */
int startCamera() {
    system(CAMERA_COMMAND);

    return 0;
}

/**
 * executes see_the_monster command
 * @return zero if all fine
 */
int seeTheMonster() {
    sleep(1);
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
        printf("PDRA ответ\n");
    }
    else if (!strcmp(line, "Да\n")) {
        printf("PZDA\n");
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

    startCamera();

    printf("\nСам гугли\n");

    return 0;
}

/**
 * executes square_solver command
 * @param argc main function argc parameter
 * @param argv main function argv parameter
 * @return zero if all fine
 */
int squareSolver(int argc, const char **argv) {
    startSolver(argc, argv);

    return 0;
}