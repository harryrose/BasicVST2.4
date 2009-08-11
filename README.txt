This project requires the VST 2.4 API (which I am not able to distribute, you need to get it from Steinberg
 http://www.steinberg.net/en/company/3rd_party_developer.html ).

When using this project as a template for other VST 2.4 projects you need to do the following

Copy the required files into VSTName/VST/

Rename the solution and the project from VSTName to some other name.

Do a project-wide find and replace for VSTName -> whatever you want (don't forget to rename the files).

Change the Unique ID in VSTName.cpp to something unique (and unless you want silly text in your code, change other default values in the files).

Change VENDORNAME and VENDORYEAR to whatever values you want (these are also in VSTName.cpp).

Change the values in the enum in VSTName.h to whatever you want.

That should more or less do it... 



This template was based fairly heavily on the VST instrument that was provided in the VST 2.4 API (vstxsynth) so if something has been left out, you might find what you're looking for in there.