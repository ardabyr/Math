#include <stdio.h>
#include <stdlib.h>
int task(int m, int n, int t, double znach[t], int ind[t]) {
	printf(&quot; transposed matrix\n & quot;);
	double und[t];
	double xnach[t];
	int ma, na, k = 0, h, f;
	double p, pp;
	for (int i = 0; i & lt; t; i++) {
		h = ind[i];
		f = (h / m);
		und[i] = (h % m) * n + f;
		xnach[i] = znach[i];
	}
	for (int i = 0; i & lt; t; i++) {
		ma = 10000;
		na = 0;
		for (int s = i; s & lt; t; s++) {
			if (ma& gt; und[s]) {
				ma = und[s];
				na = s;
			}
		}
		p = und[i];
		und[i] = und[na];
		und[na] = p;
		pp = xnach[i];
		xnach[i] = xnach[na];
		xnach[na] = pp;
	}
	for (int i = 0; i & lt; m * n; i++) {
		if (k& lt; t & amp; &amp; i == und[k]) {
			printf(&quot; % .4lf\t & quot; , xnach[k]);
			k++;
		}
		else {
			printf(&quot; 0\t & quot;);
		}
		if ((n + i) % n == (n - 1)) {

			printf(&quot; \n & quot;);
		}
	}

}
int max(int a, int b) {
	return a & gt; b ? a : b;
}
int main(int argc, char* argv[]) {
	FILE* f;
	int n, m = 0;
	f = fopen(argv[1], &quot; r & quot;);
	fscanf(f, &quot; % d & quot; , &amp; n);
	fscanf(f, &quot; % d & quot; , &amp; m);
	int ind[m * n];
	double znach[m * n];
	double q = 0;
	int t = 0;
	for (int i = 0; i & lt; m * n; i++) {
		fscanf(f, &quot; % lf & quot; , &amp; q);
		if (q != 0.) {
			ind[t] = i;
			znach[t] = q;
			t++;
		}
	}
	int k = 0;
	int choose, g = 1;
	while (g) {
		printf(&quot; 1.Print input matrix\t 2. Task\t 3. Exit \n & quot;);
		scanf(&quot; % d & quot; , &amp; choose);
		switch (choose) {
		case 1: {
			for (int i = 0; i & lt; m * n; i++) {
				if (k& lt; t & amp; &amp; i == ind[k]) {
					printf(&quot; % .4lf\t & quot; , znach[k]);
					k++;
				}
				else {
					printf(&quot; 0\t & quot;);
				}
				if ((m + i) % m == (m - 1)) {
					printf(&quot; \n & quot;);
				}
			}
			printf(&quot; --------------------------------\n & quot;);
			break;
		}
		case 2: {
			task(m, n, t, znach, ind);
			break;
		}
		case 3: {
			g = 0;
			break;
		}
		default: {
			printf(&quot; Wrong input\n & quot;);
		}
		}
	}

	return 0;
}
