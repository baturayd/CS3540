enum boolean {False, True};
typedef enum boolean Bool;
double *  diff( double  a[], int  num_elements ); 
double *  factor( double  a[], int  num_elements ); 
int arraycol( double  a[], double low, double high, double diff);
void linspace( double  a[], double low, double high, int num);
double max(double x[], int n);
double min(double x[], int n);
double mean(double x[], int n);
double median(double x[], int n);
double variance(double x[], int n);
double std_dev(double x[], int n);
double ave_power(double x[], int n);
double ave_magn(double x[], int n);
int crossings(double x[], int n);
