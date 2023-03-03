// intrfacePCI4.h
//
// Define an Interface Guid for pci429_4win device class.
// This GUID is used to register (IoRegisterDeviceInterface)
// an instance of an interface so that user application
// can control the pci429_4win device.
//
//  {A737F898-2B39-4841-B7A9-2CDD5463BDA8}
DEFINE_GUID(GUID_DEVINTERFACE_PCI429_4WIN,
	0x80cd09bd, 0x75a5, 0x4a78, 0x91, 0x33, 0xde, 0xaa, 0x28, 0x15, 0x21, 0x88);

// {80CD09BD-75A5-4a78-9133-DEAA28152188}

//IMPLEMENT_OLECREATE(<<class>>, <<external_name>>, 
//0x80cd09bd, 0x75a5, 0x4a78, 0x91, 0x33, 0xde, 0xaa, 0x28, 0x15, 0x21, 0x88);

//static const GUID <<name>> = 
//{ 0x80cd09bd, 0x75a5, 0x4a78, { 0x91, 0x33, 0xde, 0xaa, 0x28, 0x15, 0x21, 0x88 } };


// Define a Setup Class GUID for pci429_4win Class. This is same
// as the PCI429_4WIN CLASS guid in the INF files.
//
//  {505AC786-E37F-497F-A963-E08B9CA91EAC}
//DEFINE_GUID(GUID_DEVCLASS_PCI429_4WIN,
  //  0x505AC786, 0xE37F, 0x497F, 0xA9, 0x63, 0xE0, 0x8B, 0x9C, 0xA9, 0x1E, 0xAC);
DEFINE_GUID(GUID_DEVCLASS_PCI429_4WIN,
    0x7e5fedf0, 0xe996, 0x4487, 0x88, 0x74, 0xb5, 0xd7, 0x83, 0xb9, 0xf3, 0x2b);

// GUID definition are required to be outside of header inclusion pragma to avoid
// error during precompiled headers.
//
