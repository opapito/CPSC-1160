#include "social_distancing.h"

int const N = 12;

bool const map[N][N] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, },
    { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
};

static bool too_close(int x, int y) {
  for (int xx = -2; xx <= +2; xx++ ){
    if (x + xx >= 0 && x + xx < N && map[y][x + xx]) return true;
  }
  for (int yy = -2; yy <= +2; yy++ ){
    if (y + yy >= 0 && y + yy < N && map[y + yy][x]) return true;
  }
  return false;
}

int social_distancing (int x, int y){
  if ( x == N - 1 && y == N - 1)  return 1; // if we first arrive at the edge x and y, there is only one path
  if (x >= N || y >= N)           return 0; // if we are out of bounds, there is no path
  if (too_close(x, y))            return 0; // wrong way
  return social_distancing (x + 1, y) + social_distancing (x, y + 1);

}