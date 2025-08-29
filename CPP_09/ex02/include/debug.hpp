#ifndef DEBUG_HPP
# define DEBUG_HPP

// debug.tpp

template <typename Container>
void	debugMainChainSorted(const Container& c, int recDepth, int blockSize, int numBlocks, int numPending);

template <typename Container>
void	debugVecRearranged(const Container& c, const Container& insertionOrder, int posPending);

template <typename Container>
void	debugPreInsert(const Container& c, int pendIdx, int end, int k, int numMainBlocks, int numComp);

template <typename Container>
void	debugPostInsert(const Container& c, int pendIdx, int insertPos, int numComp);

# include "debug.tpp"

#endif
