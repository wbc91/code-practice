/*
ID: 08300242
LANG: C++
TASK: castle
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE*fin, *fout;
int M, N;
int node[2510];
int visited[2510];
int Rooms[2510];
int room = 0;
int maxSize = 0;
int wallCount = 0;

typedef struct Wall
{
	Wall();
	int index;
	char dir;
	int room;
}Wall;

Wall::Wall():index(0),dir('W'),room(0){};

Wall walls[10050];

void judgeWall(int index, char dir) {
	walls[wallCount].index = index;
	walls[wallCount].dir = dir;
	++wallCount;
}

int dfs(int index) {
	if (visited[index]) {
		return 0;
	}
	visited[index] = room+1;
	int result = 1;
	int west=0, north=0, east=0, south=0;
	switch(node[index]) {
		case 1: {
			west = 1;
			break;
		}
		case 2: {
			north = 1;
			break;	
		}
		case 3: {
			west = 1;
			north = 1;
			break;	
		}
		case 4: {
			east = 1;
			break;	
		}
		case 5: {
			west = 1;
			east = 1;
			break;	
		}
		case 6: {
			north = 1;
			east = 1;
			break;	
		}
		case 7: {
			west = 1;
			north = 1;
			east = 1;
			break;	
		}
		case 8: {
			south = 1;
			break;	
		}
		case 9: {
			west = 1;
			south = 1;
			break;	
		}
		case 10: {
			north = 1;
			south = 1;
			break;	
		}
		case 11: {
			west = 1;
			north = 1;
			south = 1;
			break;	
		}
		case 12: {
			east = 1;
			south = 1;
			break;	
		}
		case 13: {
			west = 1;
			east = 1;
			south = 1;
			break;	
		}
		case 14: {
			north = 1;
			east = 1;
			south = 1;
			break;	
		}
		case 15: {
			west = 1;
			north = 1;
			east = 1;
			south = 1;
			break;	
		}
		default:
		break;
	}

	if (!west) {
		result += dfs(index-1);
	}
	else {
		judgeWall(index, 'W');
	}
	if (!north) {
		result += dfs(index-M);
	}
	else {
		judgeWall(index, 'N');
	}
	if (!east) {
		result += dfs(index+1);
	}
	else {
		judgeWall(index, 'E');
	}
	if (!south) {
		result += dfs(index+M);
	}
	else {
		judgeWall(index, 'S');
	}
	return result;
}

int main(void) 
{
	fin = fopen("castle.in", "r");
	fout = fopen("castle.out", "w");
	memset(node, 0, sizeof(node));
	memset(visited, 0, sizeof(visited));
	memset(Rooms, 0, sizeof(Rooms));

	fscanf(fin, "%d %d", &M, &N);
	int index = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			fscanf(fin, "%d", &node[index++]);
		}
	}

	for (int i = 0; i < index; i++) {
		int size = dfs(i);
		if (size) {
			Rooms[room++] = size;
			maxSize = maxSize > size?maxSize:size;
		}
	}

	int maxRmSize = 0;
	int maxWallIndex = 0;
	for (int i = 0; i < wallCount; i++) {
		int wIndex = walls[i].index;
		int wDir = walls[i].dir;
		int size = 0;
		int antIndex = 0;
		switch(wDir) {
			case 'W':{
				// antIndex = wIndex-1;
				continue;
				break;
			}
			case 'N':{
				antIndex = wIndex-M;
				break;
			}
			case 'E':{
				antIndex = wIndex+1;
				break;
			}
			case 'S':{
				// antIndex = wIndex+M;
				continue;
				break;
			}
			default: break;
		}

		if (antIndex >= 0 && antIndex < M*N &&((antIndex/M) == (wIndex/M) || (antIndex%M) == (wIndex%M)) && visited[wIndex] != visited[antIndex]) {
			size = Rooms[visited[wIndex]-1]+Rooms[visited[antIndex]-1];
		}
		if (size > maxRmSize) {
			maxRmSize = size;
			maxWallIndex = i;
		}
		else if (size == maxRmSize) {
			int index1 = walls[maxWallIndex].index;
			int dir1 = walls[maxWallIndex].dir;
			int index2 = walls[i].index;
			int dir2 = walls[i].dir;

			int westDis1 = index1%M+1;
			int southDis1 = N-(index1/M);

			int westDis2 = index2%M+1;
			int southDis2 = N-(index2/M);

			if (westDis1 > westDis2 || westDis2 > westDis1) {
				if(westDis2 < westDis1) {
					maxWallIndex = i;
				}
			}
			else if (southDis1 > southDis2 || southDis2 > southDis1) {
				if (southDis2 < southDis1) {
					maxWallIndex = i;
				}
			}
			else {
				if(dir2 == 'N') {
					maxWallIndex = i;
				}
			}
		}
	}
	fprintf(fout, "%d\n", room);
	fprintf(fout, "%d\n", maxSize);
	fprintf(fout, "%d\n", maxRmSize);
	Wall wall = walls[maxWallIndex];
	fprintf(fout, "%d %d %c\n", wall.index/M+1, wall.index%M+1, wall.dir);

}
