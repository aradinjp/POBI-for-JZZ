//#ifndef APTEKA_TYPEDEF_H
//#define APTEKA_TYPEDEF_H
#include "Client.h"
#include "ClientType.h"
#include "Order.h"
#include "Transaction.h"

#include "Default.h"
#include "Honorary.h"

#include "ClientRepository.h"
#include "OrderRepository.h"
#include "TransactionRepository.h"

#include "ClientMenager.h"
#include "OrderMenager.h"
#include "TransactionMenager.h"

#include <memory>

class Client;
class ClientType;
class Order;
class Transaction;

//type
class Default;
class Honorary;

//repo
class ClientRepository;
class OrderRepository;
class TransactionRepository;

//menagers
class ClientMenager;
class OrderMenager;
class TransactionMenager;

typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::shared_ptr<Order> OrderPtr;
typedef std::shared_ptr<Transaction> TransactionPtr;

//type
typedef std::shared_ptr<Default> DefaultPtr;
typedef std::shared_ptr<Honorary> HonoraryPtr;

//repo
typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef std::shared_ptr<OrderRepository> OrderRepositoryPtr;
typedef std::shared_ptr<TransactionRepository> TransactionRepositoryPtr;

//menagers
typedef std::shared_ptr<ClientMenager> ClientMenagerPtr;
typedef std::shared_ptr<OrderMenager> OrderMenagerPtr;
typedef std::shared_ptr<TransactionMenager> TransactionMenagerPtr;

//predicate
typedef std::function<bool(const ClientPtr&)> ClientPredicate;
typedef std::function<bool(const OrderPtr&)> OrderPredicate;
typedef std::function<bool(const TransactionPtr&)> TransactionPredicate;

//#endif //APTEKA_TYPEDEF_H
