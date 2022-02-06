#include "header.h"
//strMyGame gameStr;

strMyGame lightGame;

int main() {
	while (lightGame.agan) {
		makePlateLight(lightGame);
		while (lightGame.status == IN_PROGRESS) {
			if (lightGame.step % 2 == 1) {
				turnHuman(lightGame);
				if (checkWinSituationLight(lightGame, lightGame.human)) {
					lightGame.status = WON_HUMAN;
				}
			}
			else {
				turnAi(lightGame);
				if (checkWinSituationLight(lightGame, lightGame.ai)) {
					lightGame.status = WON_AI;
				}
			}
			drawPlate(lightGame);
		}
		congrat(lightGame);
		askAgan(lightGame);
	}
}