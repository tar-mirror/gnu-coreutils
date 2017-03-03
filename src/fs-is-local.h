/* Map each S_MAGIC_* value to 1, 0 or -1.
   1 if it is known to be a remote file system type,
   0 if it is known to be a local file system type, or -1 otherwise.  */
static inline int
is_local_fs_type (unsigned long int magic)
{
  switch (magic)
    {
      case S_MAGIC_ADFS: return 1;
      case S_MAGIC_AFFS: return 1;
      case S_MAGIC_AFS: return 0;
      case S_MAGIC_ANON_INODE_FS: return 1;
      case S_MAGIC_AUFS: return 0;
      case S_MAGIC_AUTOFS: return 1;
      case S_MAGIC_BEFS: return 1;
      case S_MAGIC_BDEVFS: return 1;
      case S_MAGIC_BFS: return 1;
      case S_MAGIC_BINFMTFS: return 1;
      case S_MAGIC_BTRFS: return 1;
      case S_MAGIC_CGROUP: return 1;
      case S_MAGIC_CIFS: return 0;
      case S_MAGIC_CODA: return 0;
      case S_MAGIC_COH: return 1;
      case S_MAGIC_CRAMFS: return 1;
      case S_MAGIC_CRAMFS_WEND: return 1;
      case S_MAGIC_DEBUGFS: return 1;
      case S_MAGIC_DEVFS: return 1;
      case S_MAGIC_DEVPTS: return 1;
      case S_MAGIC_ECRYPTFS: return 1;
      case S_MAGIC_EFS: return 1;
      case S_MAGIC_EXT: return 1;
      case S_MAGIC_EXT2: return 1;
      case S_MAGIC_EXT2_OLD: return 1;
      case S_MAGIC_FAT: return 1;
      case S_MAGIC_FHGFS: return 0;
      case S_MAGIC_FUSEBLK: return 0;
      case S_MAGIC_FUSECTL: return 0;
      case S_MAGIC_FUTEXFS: return 1;
      case S_MAGIC_GFS: return 0;
      case S_MAGIC_GPFS: return 0;
      case S_MAGIC_HFS: return 1;
      case S_MAGIC_HPFS: return 1;
      case S_MAGIC_HUGETLBFS: return 1;
      case S_MAGIC_MTD_INODE_FS: return 1;
      case S_MAGIC_INOTIFYFS: return 1;
      case S_MAGIC_ISOFS: return 1;
      case S_MAGIC_ISOFS_R_WIN: return 1;
      case S_MAGIC_ISOFS_WIN: return 1;
      case S_MAGIC_JFFS: return 1;
      case S_MAGIC_JFFS2: return 1;
      case S_MAGIC_JFS: return 1;
      case S_MAGIC_KAFS: return 0;
      case S_MAGIC_LUSTRE: return 0;
      case S_MAGIC_MINIX: return 1;
      case S_MAGIC_MINIX_30: return 1;
      case S_MAGIC_MINIX_V2: return 1;
      case S_MAGIC_MINIX_V2_30: return 1;
      case S_MAGIC_MINIX_V3: return 1;
      case S_MAGIC_MQUEUE: return 1;
      case S_MAGIC_MSDOS: return 1;
      case S_MAGIC_NCP: return 0;
      case S_MAGIC_NFS: return 0;
      case S_MAGIC_NFSD: return 0;
      case S_MAGIC_NILFS: return 1;
      case S_MAGIC_NTFS: return 1;
      case S_MAGIC_OPENPROM: return 1;
      case S_MAGIC_OCFS2: return 0;
      case S_MAGIC_PANFS: return 0;
      case S_MAGIC_PIPEFS: return 0;
      case S_MAGIC_PROC: return 1;
      case S_MAGIC_PSTOREFS: return 1;
      case S_MAGIC_QNX4: return 1;
      case S_MAGIC_QNX6: return 1;
      case S_MAGIC_RAMFS: return 1;
      case S_MAGIC_REISERFS: return 1;
      case S_MAGIC_ROMFS: return 1;
      case S_MAGIC_RPC_PIPEFS: return 1;
      case S_MAGIC_SECURITYFS: return 1;
      case S_MAGIC_SELINUX: return 1;
      case S_MAGIC_SMB: return 0;
      case S_MAGIC_SOCKFS: return 1;
      case S_MAGIC_SQUASHFS: return 1;
      case S_MAGIC_SYSFS: return 1;
      case S_MAGIC_SYSV2: return 1;
      case S_MAGIC_SYSV4: return 1;
      case S_MAGIC_TMPFS: return 1;
      case S_MAGIC_UDF: return 1;
      case S_MAGIC_UFS: return 1;
      case S_MAGIC_UFS_BYTESWAPPED: return 1;
      case S_MAGIC_USBDEVFS: return 1;
      case S_MAGIC_V9FS: return 1;
      case S_MAGIC_VXFS: return 1;
      case S_MAGIC_XENFS: return 1;
      case S_MAGIC_XENIX: return 1;
      case S_MAGIC_XFS: return 1;
      case S_MAGIC_XIAFS: return 1;
      default: return -1;
    }
}
