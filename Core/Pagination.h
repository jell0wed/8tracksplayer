#ifndef PAGINATION_H
#define PAGINATION_H

/**
 Simple class that represent the pagination used in the 
 response and request of the program
*/

namespace tracksAPI
{
	class Pagination {
	public:
		Pagination(int currentPage, int nextPage = 0, int previousPage = 0)
		{
			this->currentPage = currentPage;
			this->nextPage = nextPage;
			this->previousPage = previousPage;
		};

		Pagination()
		{
			this->currentPage = 0;
			this->nextPage = 0;
			this->previousPage = 0;
			this->totalEntries = 0;
			this->totalPages = 0;
		};

		int getCurrentPage() const { return this->currentPage; };
		int getNextPage() const { return this->nextPage; };
		int getPreviousPage() const { return this->previousPage; };
		int getTotalEnties() const { return this->totalEntries; }
		int getTotalPages() const { return this->totalPages; };
		int getPerPage() const { return this->perPage; };

		void setCurrentPage(int p) { this->currentPage = p; };
		void setNextPage(int p) { this->nextPage = p; };
		void setPreviousPage(int p) { this->previousPage = p; }
		void setTotalEntries(int n) { this->totalEntries = n; };
		void setTotalPages(int n) { this->totalPages = n; };
		void setPerPage(int n) { this->perPage = n; };
	private:
		int currentPage;
		int nextPage;
		int previousPage;
		int totalEntries;
		int totalPages;
		int perPage;
	};
}

#endif