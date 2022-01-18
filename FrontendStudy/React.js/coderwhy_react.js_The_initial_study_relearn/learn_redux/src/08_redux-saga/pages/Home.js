import React, { PureComponent } from 'react'
import { connect } from 'react-redux'

import { fetchHomeMultidataAction } from '../store/actionCreators'

class Home extends PureComponent {
  render() {
    return <h2>Home</h2>
  }
  componentDidMount() {
    this.props.getHomeMultidata()
  }
}

const mapStateToProps = state => {
  return {}
}

const mapDispatchToProps = dispatch => {
  return {
    getHomeMultidata() {
      dispatch(fetchHomeMultidataAction)
    }
  }
}

export default connect(mapStateToProps, mapDispatchToProps)(Home)
