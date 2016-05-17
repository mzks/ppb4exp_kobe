{
	double hiv[200];
	double hive[200];
	double p1[200];
	double p1e[200];
	double p2[200];
	double p2e[200];

	ifstream ifs("peak.txt");
	int i = 0;
	const double f = 3.26875e16;
	const double fe= 5.48510e11;
	const double e=1.60217662e-19;

	while (ifs >> hiv[i] >> p1[i] >> p1e[i]>> p2[i]>>p2e[i]){
		hive[i]=0.5;
		p1[i] = p1[i] / f;
		p1e[i] = sqrt((p1e[i]/f)*(p1e[i]/f)+(p1[i]/f/f*fe)*(p1[i]/f/f*fe));
		p2[i] = p2[i] / f;
		p2e[i] = sqrt((p2e[i]/f)*(p2e[i]/f)+(p2[i]/f/f*fe)*(p2[i]/f/f*fe));
		i++;
	}


	TGraphErrors *tg1 = new TGraphErrors(i,hiv,p1, hive, p1e);
	TGraphErrors *tg2 = new TGraphErrors(i,hiv,p2, hive, p2e);
	tg1->SetTitle("Gain Curve");
	tg1->GetXaxis()->SetTitle("High Voltage(V)");
	tg1->GetYaxis()->SetTitle("(C)");

	tg1->Draw("AEP");
	tg2->Draw("P");
}
