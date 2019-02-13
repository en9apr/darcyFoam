    Info<< "Reading field T\n" << endl;

// Declaration of the pressure field p
// * It is an instance of the object volScalarField (scalar field defined at the cells center),
// * The file «p» must be read at the frist time step to satisfy the constructor. The initial values and boundary conditions are defined during the loading of 0/p.


	volScalarField p
    (
        IOobject
        (
            "p",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE		
        ),
        mesh
    );

// Declaration of the velocity vector field U
// * It is an instance of the object volVectorField (vector field defined at the cells center),
// * U is not read from a file (even if 0/U exist)
// * To satisfy the constructor of the object volVectorField, units and initial values are defined with an additional argument. By default, the boundary conditions are zeroGradient,
// * The file « U » will be written at every output times.

    volVectorField U
    (
        IOobject
        (
            "U",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        mesh,
		dimensionedVector("U", dimensionSet(0,1,-1,0,0,0,0),vector::zero)
    );


    Info<< "Reading transportProperties\n" << endl;

    IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    );

// Declaration of the fluid viscosity mu and the permeability k.
// They will be loaded from « constant/transportProperties »

    Info<< "Reading diffusivity k\n" << endl;

    dimensionedScalar k
    (
        transportProperties.lookup("k")
    );

    Info<< "Reading fluid viscosity mu\n" << endl;

    dimensionedScalar mu
    (
        transportProperties.lookup("mu")
    );



