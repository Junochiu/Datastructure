/*	=================== graphInsArc ================== 	Adds an arc vertex between two vertices.	   Pre    graph is a pointer to a graph	          fromKey is pointer to start vertex key	          toKey   is pointer to dest'n vertex key	   Post   Arc added to adjacency list	   Return success  +1 if successful	                   -1 if memory overflow                      -2 if fromKey not found	                   -3 if toKey not found*/int graphInsArc (GRAPH* graph, void* pFromKey, void* pToKey){//	Local Definitions 	ARC*    newPtr;	ARC*    arcPredPtr;	ARC*    arcWalkPtr;	VERTEX* vertFromPtr;	VERTEX* vertToPtr;//	Statements 	newPtr = (ARC*)malloc(sizeof(ARC));	if (!newPtr)	   return (-1);	// Locate source vertex 	vertFromPtr = graph->first;	while (vertFromPtr && (graph->compare(pFromKey,	                       vertFromPtr->dataPtr) > 0))	   {	    vertFromPtr = vertFromPtr->pNextVertex;	   } // while vertFromPtr && 	if (!vertFromPtr || (graph->compare(pFromKey,	                     vertFromPtr->dataPtr) != 0))	   return (-2);		// Now locate to vertex 	vertToPtr   = graph->first;	while (vertToPtr 	       && graph->compare(pToKey, vertToPtr->dataPtr) > 0)	   {	    vertToPtr   = vertToPtr->pNextVertex;	   } // while vertToPtr && 	if (!vertToPtr 	|| (graph->compare(pToKey, vertToPtr->dataPtr) != 0))	   return (-3);	   	// From and to vertices located. Insert new arc 	++vertFromPtr->outDegree;	++vertToPtr  ->inDegree;	newPtr->destination = vertToPtr;	if (!vertFromPtr->pArc)	   {	    // Inserting first arc for this vertex 	    vertFromPtr->pArc = newPtr;	    newPtr-> pNextArc = NULL;	    return 1;	   } // if new arc 		// Find insertion point in adjacency (arc) list 	arcPredPtr = NULL;	arcWalkPtr = vertFromPtr->pArc;	while (arcWalkPtr	       && graph->compare(pToKey,	                 arcWalkPtr->destination->dataPtr) >= 0)	   {	    arcPredPtr = arcWalkPtr;	    arcWalkPtr = arcWalkPtr->pNextArc;	   } // arcWalkPtr && 		if (!arcPredPtr)	    // Insertion before first arc 	    vertFromPtr->pArc    = newPtr;	else	    arcPredPtr->pNextArc = newPtr;	newPtr->pNextArc = arcWalkPtr;    return 1;}	// graphInsArc 