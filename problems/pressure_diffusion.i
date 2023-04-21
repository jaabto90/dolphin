[Mesh]
  type = GeneratedMesh 
  dim = 2 #Dimension of the mesh
  nx = 100 #Number of elements in the x direction
  ny = 10 #Number of elements a
  xmax = 0.304 #Length of test chamber
  ymax = 0.0257 #Test chamber radius
[]

[Problem]
  type = FEProblem
  coord_type = RZ 
  rz_coord_axis = X
[]

[Variables]
  [pressure]
    #Adds a linear Lagrange variable by default
  []
[]

[Kernels]
  [diffusion]
    type = ADDiffusion #Laplacian operator
    variable = pressure #Operate on the "pressure" variable from above 
  []
[]

[BCs]
  [inlet]
    type = ADDirichletBC #Simple u=value BC
    variable = pressure 
    boundary = left #Name of a sideset in the mesh
    value = 4000  
  []
  [outlet]
    type = ADDirichletBC
    variable = pressure
    boundary = right
    value = 0  
  []
[]

[Executioner]
  type = Steady #Steady state problem
  solve_type = NEWTON

  #Set PETSc parameters to optimize solver efficiency
  petsc_options_iname = '-pc_type -pc_hypre_type' # PETSc option pais with values below
  petsc_options_value = ' hypre    boomeramg'
[]

[Outputs]
  exodus = true #Output Exodus format
[]

