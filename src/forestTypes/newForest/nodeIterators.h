#ifndef nodeIterators_h
#define nodeIterators_h

#include <vector>
#include "obsIndexAndClassVec.h"

namespace fp{

	class nodeIterators
	{
		protected:
			std::vector<std::vector<int>::iterator > iteratorHolderBegin;
			std::vector<std::vector<int>::iterator > iteratorHolderEnd;
			std::vector<std::vector<int>::iterator > iteratorHolderSplit;

		public:
			nodeIterators(int numClasses){
				iteratorHolderBegin.resize(numClasses);
				iteratorHolderEnd.resize(numClasses);
			}

			inline void insertBeginIterator(const std::vector<int>::iterator& beginIter, int iterClass){
				iteratorHolderBegin[iterClass] = beginIter;
			}

			inline const std::vector<int>::iterator& returnBeginIterator(int iterClass){
				return iteratorHolderBegin[iterClass];
			}

inline const std::vector<int>::iterator& returnSplitIterator(int iterClass){
				return iteratorHolderSplit[iterClass];
			}

			inline void insertEndIterator(const std::vector<int>::iterator& endIter, int iterClass){
				iteratorHolderEnd[iterClass] = endIter;
			}

			inline const std::vector<int>::iterator& returnEndIterator(int iterClass){
				return iteratorHolderEnd[iterClass];
			}

			inline void setInitialIterators(obsIndexAndClassVec& indexHolder){
				for(int i = 0; i < (int)iteratorHolderBegin.size(); ++i){
					iteratorHolderBegin[i] = indexHolder.returnClassVector(i).begin();
					iteratorHolderEnd[i] = indexHolder.returnClassVector(i).end();
				}
			}


			inline void setNodeIterators(nodeIterators& nodeIters, bool isLeftNode){
				if(isLeftNode){
					iteratorHolderBegin = nodeIters.iteratorHolderBegin;
					iteratorHolderEnd = nodeIters.iteratorHolderSplit;
				}	else{
					iteratorHolderBegin = nodeIters.iteratorHolderSplit;
					iteratorHolderEnd = nodeIters.iteratorHolderEnd;
				}
			}

			inline void setVecOfClassSizes(std::vector<int>& classSizes){
				//TODO: duplicate work.  should not grow, shrink, and regrow this vector.
				classSizes.clear();
				for(int i = 0; i < (int)iteratorHolderEnd.size(); ++i){
					classSizes.push_back(iteratorHolderEnd[i]-iteratorHolderBegin[i]);
				}
			}

			inline void loadSplitIterator(std::vector<int>::iterator nextIterator){
iteratorHolderSplit.push_back(nextIterator);
			}

	};

}//namespace fp
#endif //nodeIterators_h
