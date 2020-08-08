Simple Implementation of ICP
-----------------------------


## Core Algorithm

1. Uniformaly Random sample both source and target point clouds 
2. Compute center of mass of 2 pcd's (S, T) of source and target:  u_s u_t
3. Center each pointclouds to mean, call them S' and T'
4. Form cross-correlation Matrix, W = sigma(s'_i*transpose(p'_j))
5. Compute SVD of W, ICP rotation becomes 
