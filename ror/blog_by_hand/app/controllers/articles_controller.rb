class ArticlesController < ApplicationController
	def new
		@article = Article.new
	end

	def create
		@article = Article.new(params[:article])
		@article.save
		redirect_to @article
	end
end
