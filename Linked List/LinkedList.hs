module LinkedList where
-- contains implementation of a linked list

-- Custom datatype LinkedList, with two data constructors. One Empty to represent NULL and second a Node containing data 'a' and another linked list.
-- LL = Null || (Data, LL)
data LinkedList a = Empty 
                    | Node a (LinkedList a)
                    deriving Show


-- Computes the length of the linked list.
listLength :: Num a => LinkedList a -> Int
listLength Empty = 0
listLength (Node _ nextNode) = 1 + listLength nextNode

-- Example
l = Node 1 (Node 2 (Node 3 Empty))
