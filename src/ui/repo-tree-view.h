#ifndef SEAFILE_CLIENT_REPO_TREE_VIEW_H
#define SEAFILE_CLIENT_REPO_TREE_VIEW_H

#include <vector>
#include <QTreeView>

class QAction;
class QContextMenuEvent;
class QEvent;
class QShowEvent;
class QHideEvent;
class QModelIndex;
class QStandardItem;

class RepoItem;
class RepoCategoryItem;
class CloudView;

class RepoTreeView : public QTreeView {
    Q_OBJECT
public:
    RepoTreeView(CloudView *view, QWidget *parent=0);

    std::vector<QAction*> getToolBarActions();

protected:
    void contextMenuEvent(QContextMenuEvent *event);
    bool viewportEvent(QEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
    void selectionChanged(const QItemSelection &selected,
                          const QItemSelection &deselected);

private slots:
    void downloadRepo();
    void showRepoDetail();
    void openLocalFolder();
    void viewRepoOnWeb();
    void onItemClicked(const QModelIndex& index);

private:
    QStandardItem* getRepoItem(const QModelIndex &index) const;

    void createActions();
    QMenu *prepareContextMenu(const RepoItem *item);
    void updateActions(const RepoItem *item);

    void showRepoItemToolTip(const RepoItem *item,
                             const QPoint& pos,
                             const QRect& rect);

    void showRepoCategoryItemToolTip(const RepoCategoryItem *item,
                                     const QPoint& pos,
                                     const QRect& rect);

    QAction *download_action_;
    QAction *show_detail_action_;
    QAction *open_local_folder_action_;
    QAction *view_on_web_action_;

    CloudView *cloud_view_;
};

#endif // SEAFILE_CLIENT_REPO_TREE_VIEW_H
