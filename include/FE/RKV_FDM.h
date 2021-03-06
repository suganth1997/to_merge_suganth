#ifndef __RKV_FDM__
#define __RKV_FDM__


#ifdef __2D__
void Compute_DOF_Conversion_Q1_FDM_UnitSquare2D(TCollection *coll,
TFEFunction2D *fesol, int N_x, int N_y, double h, 
int* &dof_conversion, double* &x_coord, double * &y_coord);

void Compute_DOF_Conversion_Q1_FDM_Rectangle2D(TCollection *coll,
TFEFunction2D *fesol, int &N_x, int &N_y,      
int* &dof_conversion, double* &x_coord, double* &y_coord);

void ComputeStages_FDM2D(int dim, CoeffFct2D *Coeffs, BoundCondFunct2D *bound_cond, 
  BoundValueFunct2D *bound_val,
  double *sol, double **stages, int current_stage, int N_x, int N_y,
  int *dof_conversion, double *x_coord, double *y_coord);

void SetBoundaryConditions_FDM2D(BoundCondFunct2D *bound_cond,
				 BoundValueFunct2D *bound_val,
				 double *sol, int N_x, int N_y, 
				 int *dof_conversion, 
				 double *x_coord, double *y_coord);

void CheckAdaptiveCriterion(double *sol, int &N_x, int &N_y, int &N_Unknowns,
			    double *x_coord, double *y_coord, double *aux_adaptive, double mesh_size);

void WriteGnuplotFDM(const char *name, double *sol, double *x_coord, 
		     double *y_coord, int N_x, int N_y);

void WriteVTKFDM(const char *name, double *sol, double *x_coord, 
		 double *y_coord, int N_x, int N_y);
#endif

void GradeMesh(int &N_x, double *x, double *h);

#ifdef __3D__
void Compute_DOF_Conversion_Q1_FDM_UnitCube3D(TCollection *coll,
					      TFEFunction3D *fesol, int N_x, int N_y, int N_z, double h,
					      int* &dof_conversion, double* &x_coord, double * &y_coord, double* &z_coord);

void CheckAdaptiveCriterion(double *sol, int &N_x, int &N_y,  int &N_z, int &N_Unknowns,
			    double *x_coord, double *y_coord, double *z_coord, 
			    double *aux_adaptive);
 
void ComputeStages_FDM3D(int dim, CoeffFct3D *Coeffs, BoundCondFunct3D *bound_cond,
			  BoundValueFunct3D *bound_val,
			  double *sol, double **stages, int current_stage, int N_x, int N_y, int N_z,
			  int *dof_conversion, double *x_coord, double *y_coord, double *z_coord); 

void SetBoundaryConditions_FDM3D(BoundCondFunct3D *bound_cond,
				 BoundValueFunct3D *bound_val,
				 double *sol, int N_x, int N_y, int N_z,
				 int *dof_conversion, 
				 double *x_coord, double *y_coord, double *z_coord);


void WriteVTKFDM(const char *name, double *sol, double *x_coord, 
		 double *y_coord, double *z_coord, int N_x, int N_y, int N_z);
#endif

void FEM2FDM(int N, double *fem_array, double *fdm_array, int *dof_conversion);

void FDM2FEM(int N, double *fdm_array, double *fem_array, int *dof_conversion);

void ComputeSolutionInNextTime_FDM2D(double *sol, double *sol_e, double **stages, int N_stages,
				     int N_x, int N_y, int N_z);	//mlh
void ComputeNewStepsize(double *sol, double *sol_e, double *sol_old, int N2, double *err, double *steps_old, int *m, bool *acc, int N_x, int *disc);		//mlh

void ConvectiveTermFDM(int dim, int i, 
		       double *coeff, double *sol_curr, double *current_stage_fdm, 
		       double **coordinates, int *offset_, int *offset1_);

void InitializeConvectiveTermFDM(int dim, int* &offset_, int* &offset1_, int *N1_);

void ClearConvectiveTermFDM(int* &offset);
#endif
