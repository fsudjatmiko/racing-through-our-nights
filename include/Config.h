#ifndef CONFIG_H
#define CONFIG_H

// Game window configuration
#define WINDOW_WIDTH 1440
#define WINDOW_HEIGHT 900

// Player configuration
#define PLAYER_SCALE 150
#define PLAYER_BASE_SPEED 8
#define PLAYER_RUN_SPEED 15

// Game stages
#define MAX_STAGES 5
#define STAGE_1_KILL_REQUIREMENT 35
#define STAGE_2_KILL_REQUIREMENT 70
#define FINAL_STAGE_KILL_REQUIREMENT 110

// Health system
#define MAX_HEALTH 5
#define HEALTH_CIRCLE_RADIUS 23

// Animation speeds
#define WALK_ANIMATION_FRAMES 8
#define ATTACK_ANIMATION_FRAMES 24
#define JUMP_ANIMATION_FRAMES 7
#define BOSS_ANIMATION_FRAMES 15
#define SHARK_ANIMATION_FRAMES 6

// Enemy speeds
#define ORC_SPEED 10
#define BERSERKER_SPEED 17
#define KNIGHT_SPEED 20
#define SHAMAN_BULLET_SPEED 18
#define SHARK_SPEED 22

// Asset paths
#define ASSETS_PATH "assets/"
#define CHARACTERS_PATH "assets/characters/"
#define ENEMIES_PATH "assets/enemies/"
#define BACKGROUNDS_PATH "assets/backgrounds/"
#define UI_PATH "assets/ui/"

// Floor levels
#define FLOOR_1_OFFSET -150
#define FLOOR_2_OFFSET 0
#define FLOOR_3_OFFSET 150

// Weak points for boss fight
#define WEAK_SPOT_COUNT 5
#define WEAK_SPOT_RADIUS 50

#endif // CONFIG_H
