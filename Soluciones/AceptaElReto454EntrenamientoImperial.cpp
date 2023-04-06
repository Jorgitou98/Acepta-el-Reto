#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	int d, s;
	while (scanf("%d %d", &d, &s) == 2) {
		int longi, subid;
		scanf("%d %d", &longi, &subid);
		if (longi == 0 && subid == 0) {
			printf("0\n");
			continue;
		}
		int dias = 1;
		int distRest = d;
		int subidaRest = s;
		bool imposible = false;
		while (longi != 0 || subid != 0) {
			if (longi > d || subid > s) {
				imposible = true;
				string aux;
				getline(cin, aux);
				break;
			}
			if (!imposible) {
				if (distRest < longi || subidaRest < subid) {
					dias++;
					distRest = d - longi;
					subidaRest = s;
					if(subid > 0) subidaRest -= subid;
				}
				else {
					distRest -= longi;
					if (subid > 0) subidaRest -= subid;
				}
			}
			scanf("%d %d", &longi, &subid);
		}
		if (imposible) printf("DESTITUIDO\n");
		else printf("%d\n", dias); 
	}
	return 0;
}