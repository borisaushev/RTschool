#ifndef BOSSBORISS_SECRET_H
#define BOSSBORISS_SECRET_H

const char* const MOANS_SOUND_PATH = "\"C:\\Users\\bossb\\Downloads\\sanya.mp3\"";
const char* const STEREO_MADNESS_SOUND_PATH = "\"C:\\Users\\bossb\\Downloads\\stereomadness.mp3\"";
const char* const HOG_IMAGE_LINK = "\"https://avatars.mds.yandex.net/i?id=5c4f760e8659f711e41dc25a777058ab-5232402-images-thumbs&n=13\"";
const char* const SCREAMER_VIDEO_PATH = "\"C:\\Users\\bossb\\Downloads\\congrats.mp4\"";

const char* const UNMUTE_COMMAND = "nircmd.exe mutesysvolume 0";
const char* const MAX_VOLUME_COMMAND = "nircmd.exe setsysvolume 65535";
const char* const SOUND_PLAYER_COMMAND = "start wmplayer.exe ";
const char* const VIDEO_PLAYER_COMMAND = "start wmplayer.exe /fullscreen ";
const char* const EDGE_COMMAND = "start msedge --start-fullscreen ";
const char* const CAMERA_COMMAND = "\"C:\\Program Files\\WindowsApps\\Microsoft.WindowsCamera_2025.2505.2.0_x64__8wekyb3d8bbwe\\WindowsCamera.exe\"";

const int TABS_COUNT = 30;

int setMaxVolume();

int playSound(const char *soundPath);

int playVideo(const char *videoPath);

int openLink(const char* link);

int startCamera();

int countTheStars();

int seeTheMonster();

int arsen();

int squareSolver(int argc, const char **argv);

#endif //BOSSBORISS_SECRET_H