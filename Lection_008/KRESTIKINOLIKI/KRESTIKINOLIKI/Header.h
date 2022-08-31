#pragma once
enum TCell : char;
struct TCoord;
enum TProgress;
struct TGame;
void InitGame(TGame& g);
void DeInitGame(TGame& g);
void PrintGame(const TGame& g);
void Congrats(const TGame& g);
TProgress getWon(const TGame& g);
TCoord getHumanCoord(const TGame& g);
TCoord getAICoord(TGame& g);