{
	double x[200];
	double xe[200];
	double y[200];
	double ye[200];
	ifstream ifs("cal.dat");
	int i = 0;
	while (ifs >> x[i] >> y[i] >> ye[i]){
		xe[i]=0;
		x[i]*=1e-15;
		i++;
	}
	TGraphErrors *tg = new TGraphErrors(i,x,y, xe, ye);
	tg->Draw("AP");
}
