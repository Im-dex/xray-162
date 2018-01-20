#ifndef PHDEFS_H
#define PHDEFS_H
class CPHElement;
class CPHJoint;
class CPhysicsShell;

// class CPHFracture;
class CShellSplitInfo;

typedef std::pair<CPhysicsShell*, u16> shell_root;

using ELEMENT_STORAGE = std::vector<CPHElement*>;
typedef std::vector<CPHElement*>::const_iterator ELEMENT_CI;
using JOINT_STORAGE = std::vector<CPHJoint*>;
using PHSHELL_PAIR_VECTOR = std::vector<shell_root>;
typedef std::vector<shell_root>::reverse_iterator SHELL_PAIR_RI;

typedef std::vector<CPHElement*>::reverse_iterator ELEMENT_RI;

#endif